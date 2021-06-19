// The problem link : https://www.acmicpc.net/problem/17086
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,y,x,mm,ny,nx,my[]={-1,-1,-1,0,0,1,1,1},mx[]={-1,0,1,-1,1,-1,0,1},ans=0;
struct shark{
    int yy, xx;
    int move;
};

void bfs(vector<vector<int>> &v, int a, int b){
    vector<vector<bool>> ch(n,vector<bool>(m,false));
    queue<shark> q;
    q.push({a,b,0});
    ch[a][b] = true;
    while(!q.empty()){
        y = q.front().yy;
        x = q.front().xx;
        mm = q.front().move;
        q.pop();
        for(int i=0; i<8; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny<0||ny>=n||nx<0||nx>=m||ch[ny][nx]) continue;
            ch[ny][nx] = true;
            if(v[ny][nx]==1){
                if(mm+1>ans) ans = mm+1; 
                return;
            }
            q.push({ny,nx,mm+1});
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> v[i][j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]==0) bfs(v,i,j);
        }
    }
    cout << ans << "\n";
}
