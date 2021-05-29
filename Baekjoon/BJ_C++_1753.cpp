// The problem link : https://www.acmicpc.net/problem/1753
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 20001
using namespace std;

struct Edge {
    int pos;
    int dis;
    Edge(int a, int b) { pos = a, dis = b; }
    bool operator<(const Edge& next)const { // 오버로딩 // 거리가 짧은 노드가 앞에 오게 된다
        return dis > next.dis;
    }
};

int v, e, k; // 정점, 간선, 노드
vector<pair<int, int>> arr[MAX];
vector<int> map;

void bfs() {
    priority_queue<Edge>pq;
    pq.push({ k,0 });
    int pos, dis, npos, ndis;
    while (!pq.empty()) {
        pos = pq.top().pos;
        dis = pq.top().dis;
        pq.pop();
        for (int i = 0; i < arr[pos].size(); i++) {
            npos = arr[pos][i].first;
            ndis = arr[pos][i].second;
            if (map[npos] > map[pos] + ndis) {
                map[npos] = map[pos] + ndis;
                pq.push({ npos,map[npos] });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c;
    cin >> v >> e;
    cin >> k;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({ b,c });
    }
    map.resize(v + 1, 1e9);
    map[k] = 0;
    bfs();
    for (int i = 1; i <= v; i++) {
        if (map[i] != 1e9) cout << map[i] << "\n";
        else cout << "INF" << "\n";
    }
    return 0;
}
