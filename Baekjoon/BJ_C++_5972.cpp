// The problem link : https://www.acmicpc.net/problem/5972
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,from,to,dis;
vector<vector<pair<int,int>>> v;
vector<int> map;

int dijkstra(){
    int pos,next,dis,ndis;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    map[1] = 0;
    pq.push({1,0});
    while(!pq.empty()){
        pos = pq.top().first;
        dis = pq.top().second;
        pq.pop();
        for(int i=0; i<v[pos].size(); i++){
            next = v[pos][i].first;
            ndis = v[pos][i].second;
            if(map[next]>map[pos]+ndis){
                map[next] = map[pos]+ndis;
                pq.push({next,ndis});
            }
        }
    }
    return map[n];
}

void input(){
    cin >> n >> m;
    v.resize(n+1);
    map.resize(n+1,987654321);
    for(int i=0; i<m; i++){
        cin >> from >> to >> dis;
        v[from].push_back({to,dis});
        v[to].push_back({from,dis});
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << dijkstra() << "\n";
    return 0;
}
