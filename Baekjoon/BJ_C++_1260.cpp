#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n = 0, m = 0, s = 0, temp = 0;
vector <int> v[1001];
bool ch[1001] = {false,};

void bfs(int x){
    queue<int> q;
    q.push(x);
    ch[x] = true;
    while(!q.empty()){
        temp = q.front();
        cout << temp << " ";
        q.pop();
        for(int i=0; i<v[temp].size(); i++){
            if(!ch[v[temp][i]]){
                ch[v[temp][i]] = true;
                q.push(v[temp][i]);
            }
        }
    }
}

void dfs(int x){
    cout << x << " ";
    ch[x] = true;
    for(int i=0; i<v[x].size(); i++){
        if(!ch[v[x][i]]){
            dfs(v[x][i]);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0, b = 0;
    cin >> n >> m >> s;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    dfs(s);
    memset(ch,false,sizeof(ch));
    cout << "\n";
    bfs(s);
    cout << "\n";

    return 0;
}
