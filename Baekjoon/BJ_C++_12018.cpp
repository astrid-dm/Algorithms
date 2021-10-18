// The problem link : https://www.acmicpc.net/problem/12018
// The result : 2156KB, 0ms
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0, m, a, b, c, temp = 0, res = 0;
    cin >> n >> m;
    vector<int> v[100];
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        for (int j = 0; j < a; j++) {
            cin >> c;
            v[i].push_back(c);
        }
        sort(v[i].begin(), v[i].end());
        if (v[i].size() < b) ans.push_back(1);
        else ans.push_back(v[i][a-b]);
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        if (temp + i > m) break; 
        else { temp += i; res++; }
    }
    cout << res << "\n";
    return 0;
}
