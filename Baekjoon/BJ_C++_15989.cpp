// The problem link : https://www.acmicpc.net/problem/15989
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, arr[10001], temp = 0;
    for(int i=0; i<=10000; i++) arr[i] = 0;
    arr[0] = 1;
    cin >> n;
    for(int i=1; i<=3; i++){
        for(int j=i; j<=10000; j++){
            arr[j] += arr[j-i];
        }
    }
    while(n--){
        cin >> temp;
        cout << arr[temp] << "\n";
    }
    return 0;
}
