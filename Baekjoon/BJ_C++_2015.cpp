// The problem link : https://www.acmicpc.net/problem/2015
// The result : 12320KB, 44ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    unsigned long long k = 0, ans = 0;
    cin >> n >> k;
    vector<int> v(n+1,0);
    vector<int> sum(n+1,0);
    unordered_map<long long, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
    }
    mp[0]++;
    for (int i = 1; i <= n; i++) {
        ans += mp[sum[i] - k];
        mp[sum[i]]++;
    }
    cout << ans << "\n";
    return 0;
}
