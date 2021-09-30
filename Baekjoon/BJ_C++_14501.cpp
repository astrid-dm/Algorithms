// The problem link : https://www.acmicpc.net/problem/14501
// The result : 2020KB, 0ms
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 16

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, ans = 0, day, pay, maxi=0;
    cin >> n;
    vector<pair<int, int>> v(n + 1, { 0,0 });
    vector<int> sum(n + 2,0);
    for (int i = 1; i <= n; i++) {
        cin >> day >> pay;
        v[i] = {day,pay};
    }
    for (int i = 1; i <= n; i++) {
        day = v[i].first;
        sum[i] = max(maxi,sum[i]);
        if (i + day <= n+1) sum[i + day] = max(sum[i + day], sum[i] + v[i].second);
        maxi = max(maxi, sum[i]);
    }
    for (int i = 1; i <= n+1; i++) ans = max(ans, sum[i]);
    cout << ans << "\n";
    return 0;
}
