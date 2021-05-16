#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> v[51];
vector<int> dist;

void dijkstra(int K){
    int pos, dis, next, ndis;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({1,0});
    while(!q.empty()){
        pos = q.top().first;
        dis = q.top().second;
        q.pop();
        for(int i=0; i<v[pos].size(); i++){
            next = v[pos][i].first;
            ndis = v[pos][i].second;
            if(dist[next]>dist[pos]+ndis){
                dist[next] = dist[pos]+ndis;
                q.push({next,ndis});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    dist.resize(N+1, 1e9);
    for(int i=0; i<road.size(); i++){
        int a= road[i][0], b = road[i][1], c = road[i][2];
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dist[1] = 0;
    dijkstra(K);
    for(int i=1; i<dist.size(); i++) if(dist[i]<=K) answer++;
    return answer;
}
