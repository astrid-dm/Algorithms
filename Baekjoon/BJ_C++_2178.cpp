#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n = 0, m = 0, ty = 0, tx = 0, ny = 0, nx = 0;
int arr[101][101], my[4] = {1,0,-1,0}, mx[4] = {0,1,0,-1};
int ch[101][101];

bool track(int y, int x){
    if(y<1||y>n||x<1||x>m||arr[y][x]==0||ch[y][x]>0) return false;
    return true;
}

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    while(!q.empty()){
        ty = q.front().first;
        tx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            ny = ty + my[i];    
            nx = tx + mx[i];
            if(ny==n&&nx==m){
                cout << ch[ty][tx] + 1 << "\n";
                exit(0);
            }
            if(track(ny,nx)){
                q.push(make_pair(ny,nx));
                ch[ny][nx] = ch[ty][tx] + 1;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> c;
            arr[i][j] = c-48;
        }
    }

    ch[1][1] = 1;
    bfs(1,1);

    return 0;
}
