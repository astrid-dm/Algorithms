// The problem link : https://www.acmicpc.net/problem/2961
// Thr result : 2020KB, 0ms
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans = 1000000000, temp1=0, temp2 = 0;

void backtracking(vector<pair<int,int>> &v, int num, int sweet, int bitter){
    if(num==n){
        if(sweet==0&&bitter==0) return;
        ans = min(ans,abs(bitter-sweet));
        return;
    }
    temp1 = sweet*v[num].first;
    if(temp1==0) temp1 = v[num].first;
    temp2 = bitter+v[num].second;
    backtracking(v,num+1,temp1,temp2);
    backtracking(v,num+1,sweet, bitter);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    backtracking(v,0,0,0);
    cout << ans << "\n";
    return 0;
}
