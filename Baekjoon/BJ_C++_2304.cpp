// The problem link : https://www.acmicpc.net/problem/2304
// The result : 2020KB, 0ms
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,w,h,arr[1001][3],st=1001,ed=0,ans=0,column=0;
    for(int i=0; i<1001; i++){
        for(int j=0; j<3; j++) arr[i][j] = 0;
    }
    cin >> n;
    while(n--){
        cin >> w >> h;
        arr[w][0] = h;
        if(st>w) st = w;
        if(ed<w) ed = w;
    }
    for(int i=st; i<=ed; i++){
        column = max(column,arr[i][0]);
        arr[i][1] = column;
    }
    column = 0;
    for(int i=ed; i>=st; i--){
        column = max(column,arr[i][0]);
        arr[i][2] = column;
    }
    for(int i=st; i<ed; i++) ans += min(arr[i][1],arr[i][2]);
    ans += min(arr[ed][1],arr[ed][2]);
    cout << ans << "\n";
    return 0;
}
