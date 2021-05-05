#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,sum,ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++){
        if(v[i]>m) continue;
        sum = 0;
        for(int j=i; j<n; j++){
            sum+=v[j];
            if(sum>=m) break;
        }
        if(sum==m) ans++;
    }
    cout << ans << "\n";
    return 0;
}
