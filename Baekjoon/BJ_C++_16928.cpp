#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,x,y,u,v,pos,num,npos,nnum,ans,up[101],down[101],cnt[101];
bool ch[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        up[x] = y;
    }
    for(int i=0; i<m; i++){
        cin >> u >> v;
        down[u] = v;
    }
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        pos = q.front().first;
        num = q.front().second;
        q.pop();
        if(pos==100){
            cout << num << "\n";
            exit(0);
        }
        for(int i=6; i>=1; i--){
            npos = pos+i;
            nnum = num+1;
            if(npos<=100&&!ch[npos]){
                ch[npos] = true;
                cnt[npos] = nnum;
                if(up[npos]) {
                    npos = up[npos];
                    cnt[npos] = nnum;
                }
                else if(down[npos]){
                    npos = down[npos];
                    cnt[npos] = nnum;
                }
                ch[npos] = true;
                q.push({npos,nnum});
            }
        }
    }
    return 0;
}
