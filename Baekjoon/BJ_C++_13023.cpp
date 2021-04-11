#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2001
using namespace std;

bool ch[MAX][MAX];
vector<int> node[MAX];
vector<pair<int,int>> edge;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,from,to,A,B,C,D,E;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> from >> to;
        ch[from][to] = ch[to][from] = true;
        node[from].push_back(to);
        node[to].push_back(from);
        edge.push_back({from,to});
        edge.push_back({to,from});
    }
    m*=2;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(i==j) continue;
            A=edge[i].first;
            B=edge[i].second;
            C=edge[j].first;
            D=edge[j].second;
            if(A==B||A==C||A==D||B==C||B==D||C==D) continue;
            if(!ch[B][C]) continue;
            for(int x=0; x<node[D].size(); x++){
                E=node[D][x];
                if(E==A||E==B||E==C||E==D) continue;
                cout << 1 << "\n";
                return 0;
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}
