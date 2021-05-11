#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void fail() {
    cout << "0" << "\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a, b;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    int idx = 0, pos, cnt;
    if (q[idx] != 1) fail();
    queue<int> temp;
    temp.push(1);
    idx++;
    while (!temp.empty()) {
        pos = temp.front();
        temp.pop();
        pos == 1 ? cnt = v[pos].size() : cnt =  v[pos].size() - 1;
        while (cnt) {
            auto now = find(v[pos].begin(), v[pos].end(), q[idx]);
            if (now!=v[pos].end()) {
                v[pos].erase(now);
                if (v[q[idx]].size() > 1) temp.push(q[idx]);
                cnt--;
                idx++;
            }
            else fail();
        }
    }
    cout << "1" << "\n";
    return 0;
}
