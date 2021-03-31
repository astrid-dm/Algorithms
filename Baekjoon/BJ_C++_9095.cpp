#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n= 0 , temp = 0, arr[12];
    cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4; i<=11; i++) arr[i] = arr[i-3]+arr[i-2]+arr[i-1];
    while(n--){
        cin >> temp;
        cout << arr[temp] << "\n";
    }
    return 0;
}
