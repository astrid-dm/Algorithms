#include <iostream>
#define mod 1000000009
using namespace std;

long long arr[1000001][4];
const int limit = 100000;

void Input(){
    arr[1][1] = 1, arr[1][2] = 0, arr[1][3] = 0;
    arr[2][1] = 0, arr[2][2] = 1, arr[2][3] = 0;
    arr[3][1] = 1, arr[3][2] = 1, arr[3][3] = 1;
    for(int i=4; i<=limit; i++){
        arr[i][1] = arr[i-1][2] + arr[i-1][3];
        arr[i][2] = arr[i-2][1] + arr[i-2][3];
        arr[i][3] = arr[i-3][1] + arr[i-3][2];
        arr[i][1] %= mod;
        arr[i][2] %= mod;
        arr[i][3] %= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 0, temp = 0;
    cin >> t;
    Input();
    while(t--){
        cin >> temp;
        cout << (arr[temp][1] + arr[temp][2] + arr[temp][3]) % mod << "\n";
    }
    return 0;
}
