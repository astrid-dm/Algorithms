// The problem link : https://www.acmicpc.net/problem/10025
// The result : 17644 KB, 32ms
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

long long arr[MAX], dp[MAX],ans=0,temp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,n,k; // n = buckets, k = available spot +-
    cin >> n >> k;
    for(int i=0; i<MAX; ++i) {arr[i] = 0; dp[i] = 0;}
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        arr[b] = a;
    }
    dp[0] = arr[0];
    for(int i=1; i<MAX; i++) dp[i] = dp[i-1]+arr[i]; // must eat
    if(k<MAX){
        for(int i=0; i<MAX; i++){
            if(i+k<MAX && i-k>=1) temp = dp[i+k]-dp[i-k-1];
            if(temp>ans) ans = temp;
        }
        cout << ans << "\n";
    }else cout << dp[MAX-1] << "\n";
    return 0;
}
