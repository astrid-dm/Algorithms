#include <iostream>
using namespace std;

long long arr[91][2];

long long Calculation(int n){
    long long ans = 0;
    arr[1][0] = 0, arr[1][1] = 1;
    arr[2][0] = 1, arr[2][1] = 0;
    arr[3][0] = 1, arr[3][1] = 1;
    arr[4][0] = 2, arr[4][1] = 1;
    for(int i=5; i<=n; i++){
        arr[i][0] = arr[i-1][0] + arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    ans = arr[n][0] + arr[n][1];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    cin >> n;
    cout << Calculation(n) << "\n";
    return 0;
}
