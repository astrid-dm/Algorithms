// The problem link : https://www.acmicpc.net/problem/1504
#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
#define MAX 2e9
using namespace std;

int n,e,t1,t2;
unsigned long long temp1 = MAX, temp2 = MAX, ans = MAX;
vector<int> dist;
vector<vector<pair<int,int>>> v;

void dijk(int start){
    int pos, dis, next, ndis;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    for(int i=1; i<=n; i++) dist[i] = MAX;
    q.push({start,0});
    dist[start] = 0;
    while(!q.empty()){
        pos = q.top().first;
        dis = q.top().second;
        q.pop();
        for(int i=0; i<v[pos].size(); i++){
            next = v[pos][i].first;
            ndis = v[pos][i].second;
            if(dist[next]>dist[pos]+ndis){
                dist[next] = dist[pos]+ndis;
                q.push({next,dist[next]});
            }
        }
    }
}

void twoTrack(){
    int a1,a2,b1,b2;
    temp1 = dist[t1];
    temp2 = dist[t2];
    dijk(t1);
    a1 = dist[t2]; // 양방향
    b1 = dist[t2]; // 양방향
    b2 = dist[n];
    dijk(t2);
    a2 = dist[n];
    temp1 = min(ans,temp1+a1+a2);
    temp2 = min(ans,temp2+b1+b2);
    ans = min(temp1,temp2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,c;
    cin >> n >> e;
    dist.resize(n+1,MAX);
    v.resize(n+1, vector<pair<int,int>>(n+1));
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> t1 >> t2;
    dijk(1);
    twoTrack();
    if(ans==MAX) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
