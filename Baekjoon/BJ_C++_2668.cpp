#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, cnt = 0;
int arr[101];
bool check[101];
bool fin[101];
int ans[101];

void dfs(int a) {
    check[a] = true;
    if (!check[arr[a]]) dfs(arr[a]);
    else if (!fin[arr[a]]) {
        ans[cnt++] = a;
        for (int i = arr[a]; i != a; i = arr[i]) ans[cnt++] = i;
    }
    fin[a] = true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        if (!check[i]) dfs(i);
    }
    cout << cnt << "\n";
    sort(ans, ans + cnt);
    for (int i = 0; i < cnt; i++) cout << ans[i] << "\n";

    return 0;
}
