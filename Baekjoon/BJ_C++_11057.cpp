#include <iostream>
#define MAX 1001
#define MOD 10007
using namespace std;

long long arr[MAX][10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    long long ans = 0;
    cin >> n;
    for(int i=0; i<10; i++) arr[1][i] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int x=0; x<=j; x++){
                arr[i][j] += arr[i-1][x];
            }
            arr[i][j] %= MOD;
        }
    }
    for(int i=0; i<10; i++) ans += arr[n][i];
    cout << ans % MOD << "\n";
    return 0;
}
