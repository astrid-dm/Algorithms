// The problem link : https://www.acmicpc.net/problem/1253
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        int l=0, r=n-1;
        while(l<r){
            if(l==i){l++; continue;}
            if(r==i){r--;continue;}
            if(v[i]>v[l]+v[r]) l++;
            else if(v[i]==v[l]+v[r]){
                ans++;
                break;
            }
            else r--;
        }
    }
    cout << ans << "\n";
    return 0;
}
