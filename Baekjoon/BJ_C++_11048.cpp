// The problem link : https://www.acmicpc.net/problem/11048
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,my[]={1,0,1},mx[]={0,1,1},y,x,ny,nx;
    cin >> n >> m;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> v[i][j];
    }
    dp[1][1] = v[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            y = i;
            x = j;
            for(int a=0; a<3; a++){
                ny = y+my[a];
                nx = x+mx[a];
                if(ny<1||ny>n||nx<1||nx>m) continue;
                if(dp[y][x]+v[ny][nx]<=dp[ny][nx]) continue;
                dp[ny][nx] = dp[y][x]+v[ny][nx];
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
