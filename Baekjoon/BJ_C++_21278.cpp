// 2160ms, 80Kb
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

int n,m,a,b,ans=MAX,pos1=MAX,pos2=MAX;
vector<int> v[101];

void dijkstra(int pos, vector<int> &map){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,pos});
    map[pos] = 0;
    while(!pq.empty()){
        int pos = pq.top().second;
        pq.pop();
        for(int i=0; i<v[pos].size(); i++){
            int npos = v[pos][i];
            if(map[npos]>map[pos]+1){
                map[npos] = map[pos]+1;
                pq.push({map[npos],npos});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){ // n = 건물갯수, m = 도로갯수 (입력갯수)
        for(int j=i+1; j<=n; j++){
            vector<int> map(n+1,MAX);
            int disTemp =0, temp = 0;
            dijkstra(i,map);
            dijkstra(j,map);
            for(int k=1; k<=n; k++){
                if(map[k]>0) disTemp += map[k]*2;
            }
            if(disTemp<ans) {ans = disTemp; pos1 = min(i,j); pos2 = max(i,j);} // pos1 = 작은거, pos2 = 큰거
            else if(disTemp==ans){
                temp = min(i,j);
                if(pos1>temp) {ans = disTemp; pos1 = min(i,j); pos2 = max(i,j);}
                else if(pos1==temp){
                    temp = max(i,j);
                    if(pos2>temp) {ans = disTemp; pos1 = min(i,j); pos2 = max(i,j);}
                }
            }
        }
    }
    cout << pos1 << "\n" << pos2 << "\n" << ans << "\n";
    return 0;
}
