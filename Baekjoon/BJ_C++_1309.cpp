#include <iostream>
#define MAX 100000
#define MOD 9901
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[MAX][3] = {0,}, n = 0, ans = 0;
    cin >> n;
    arr[0][0] = 1, arr[0][1] = 1, arr[0][2] = 1;
    for(int i=1; i<n; i++){
        arr[i][0] = (arr[i-1][1]+arr[i-1][2]+arr[i-1][0])%MOD;
        arr[i][1] = (arr[i-1][0]+arr[i-1][2])%MOD;
        arr[i][2] = (arr[i-1][0]+arr[i-1][1])%MOD;
    }
    ans = (arr[n-1][0] + arr[n-1][1] + arr[n-1][2])%MOD;
    cout << ans << "\n";
    return 0;
}
