// The problem link : https://www.acmicpc.net/problem/10942
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void palin(vector<vector<bool>> &dp, vector<int> &v, int n){
    for(int i=1; i<=n; i++){
        dp[i][i] = true; // m의 길이가 1일 경우
    }
    for(int i=1; i<=n-1; i++){ //m의 길이가 2인 경우
        if(v[i]==v[i+1]) dp[i][i+1] = true;
    }
    for(int i=n-2; i>=1; i--){ // m의 길이가 3 이상인 경우
        for(int j=i+2; j<=n; j++){
            if(v[i]==v[j]&&dp[i+1][j-1]) dp[i][j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, m = 0, temp = 0, st, ed;
    cin >> n;
    vector<int> v(n+1,0);
    vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
    for(int i=1; i<=n; i++) cin >> v[i];
    palin(dp,v,n);
    cin >> m;
    while(m--){
        cin >> st >> ed;
        cout << dp[st][ed] << "\n";
    }
    return 0;
}
