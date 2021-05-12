#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<int> v[100001];
bool ch[100001];
int order[100001];
vector<int> dfs_order;

bool comp(int& a, int& b) {
    return order[a] < order[b];
}

void dfs(int pos) {
    if (ch[pos]) return;
    ch[pos] = true;
    dfs_order.push_back(pos);
    for (auto i : v[pos]) {
        if (!ch[i]) dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> temp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> temp[i];
        order[temp[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), comp);
    }
    dfs_order.push_back(0);
    if (temp[1] == 1) dfs(1);
    if (dfs_order == temp) cout << "1" << "\n";
    else cout << "0" << "\n";
    return 0;
}
