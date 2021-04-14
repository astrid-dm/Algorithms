#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

bool ch[MAX][MAX];
int arr[MAX][MAX] = {0,},dp[MAX][MAX] = {0,},n,m,my[]={1,-1,0,0,},mx[]={0,0,1,-1},y,x,ny,nx;
char c;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n; // m = 4, n = 2
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> c;
            arr[i][j] = c-'0';
        }
    }
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    q1.push({1,1});
    ch[1][1] = true;
    while(!q1.empty()){
        y = q1.front().first;
        x = q1.front().second;
        q1.pop();
        if(y==n&&x==m){
            cout << dp[y][x] << "\n";
            exit(0);
        }
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny>=1&&ny<=n&&nx>=1&&nx<=m&&!ch[ny][nx]){
                ch[ny][nx] = true; // 중요
                if(arr[ny][nx]==1){ // 벽
                    q2.push({ny,nx});
                    dp[ny][nx] = dp[y][x]+1;
                }
                else{ // 길
                    q1.push({ny,nx});
                    dp[ny][nx] = dp[y][x];
                }
            }
        }
        if(q1.empty()){
            q1 = q2;
            q2 = queue<pair<int,int>>();
        }
    }
    return 0;
}
