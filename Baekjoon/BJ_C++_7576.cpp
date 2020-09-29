#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int m = 0, n = 0, ans = 0;
int arr[1001][1001];
int ch[1001][1001];
int my[4] = {1,0,-1,0};
int mx[4] = {0,1,0,-1};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n; // m 가로 n 세로
    queue<pair<int,int>> q;
    int y = 0, x = 0, ny = 0, nx = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            ch[i][j] = -1;
            if(arr[i][j]==1){
                ch[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny>0&&ny<=n&&nx>0&&nx<=m){
                if(arr[ny][nx]==0&&ch[ny][nx]==-1){
                    q.push(make_pair(ny,nx));
                    ch[ny][nx] = ch[y][x] + 1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]==0&&ch[i][j]==-1){
                ans = -1;
                cout << ans << "\n";
                exit(0);
            }
            if(ans<ch[i][j]) ans = ch[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
