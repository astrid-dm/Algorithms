#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int y = 0, x = 0, ans = 0;
int my[8] = {1,1,0,1,-1,-1,0,-1};
int mx[8] = {0,1,1,-1,0,-1,-1,1};
bool check[252][252] = { false, };
int v[252][252];

bool track(int h, int w) {
    if (h<1 || h>y || w<1 || w>x || check[h][w] || v[h][w] == 0) return false;
    else return true;
}

void dfs(int h, int w) {
    check[h][w] = true;
    for (int i = 0; i < 8; i++) {
        int ny = h + my[i];
        int nx = w + mx[i];
        if (track(ny, nx)) {
            dfs(ny, nx);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0;
    cin >> y >> x;
    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            cin >> a;
            v[i][j] = a;
        }
    }
    for (int i = 1; i <= y; i++) {
        for (int j = 1;j <= x; j++) {
            if (!check[i][j] && v[i][j] == 1) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
