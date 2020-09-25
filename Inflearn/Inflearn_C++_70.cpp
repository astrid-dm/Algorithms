#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n = 0, m = 0;
vector<int> arr[6];
int ans[21];
bool check[21];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0, b = 0, x=0;
    queue<int> Q;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
    }
    Q.push(1);
    check[1] = true;
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        for (int i = 0; i < arr[x].size(); i++) {
            if (!check[arr[x][i]]) {
                check[arr[x][i]] = true;
                Q.push(arr[x][i]);
                ans[arr[x][i]] = ans[x] + 1;
            }
        }
    }
    for (int i = 2; i <= n; i++) cout << i << " : " << ans[i] << "\n";
    return 0;
}
