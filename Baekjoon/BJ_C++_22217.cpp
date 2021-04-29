#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return a>b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end(),comp);
    ans = v[0];
    for(int i=1; i<n; i++) ans = max(ans,v[i]*(i+1));
    cout << ans << "\n";
    return 0;
}
