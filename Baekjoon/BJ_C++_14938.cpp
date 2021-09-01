// The problem link : https://www.acmicpc.net/problem/14938
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 99999999
using namespace std;

int n,m,r,ans = 0;
vector<int> items(101);
vector<pair<int,int>> map[101];
vector<int> dist(101);

void getAnswer(int x){
    int temp = 0;
    for(int i=1; i<=n; i++) if(dist[i]-m<=0) temp += items[i];
    if(ans<temp) ans = temp;
}

void dijkstra(int x){
    int pos, npos, ndis;
    queue<int> pq;
    dist[x] = 0;
    pq.push(x);
    while(!pq.empty()){
        pos = pq.front();
        pq.pop();
        for(int i=0; i<map[pos].size(); i++){
            npos = map[pos][i].first;
            ndis = map[pos][i].second;
            if(dist[pos]+ndis<dist[npos]){
                dist[npos] = dist[pos]+ndis;
                pq.push(npos);
            }
        }
    }
    getAnswer(x);
}

void init(){
    for(int i=1; i<=n; i++) dist[i] = MAX;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,c;
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) cin >> items[i];
    for(int i=0; i<r; i++){
        cin >> a >> b >> c;
        map[a].push_back({b,c});
        map[b].push_back({a,c});
    }
    for(int i=1; i<=n; i++){
        init();
        dijkstra(i);
    }
    cout << ans << "\n";
    return 0;
}
