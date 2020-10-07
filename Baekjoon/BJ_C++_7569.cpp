#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int m = 0, n = 0, h = 0, ny = 0, nx = 0, nz = 0, y = 0, x = 0, z = 0, ans = -1;
int arr[101][101][101], ch[101][101][101]; // z, y, x
int my[4] = { 0,1,0,-1 };
int mx[4] = { -1,0,1,0 };
int mz[2] = { -1,1 };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;
    queue<pair<int, pair<int, int>>> q;
    for (int x = 1; x <= h; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[x][i][j];
                ch[x][i][j] = -1;
                if (arr[x][i][j] == 1) {
                    q.push(make_pair(x, make_pair(i, j)));
                    ch[x][i][j] = 0;
                }
            }
        }
    }
    while (!q.empty()) {
        nz = q.front().first;
        ny = q.front().second.first;
        nx = q.front().second.second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            if (i < 4) {
                y = ny + my[i];
                x = nx + mx[i];
                if (y <= n && y >= 1 && x <= m && x >= 1) {
                    if (arr[nz][y][x] == 0 && ch[nz][y][x] == -1) {
                        q.push(make_pair(nz, make_pair(y, x)));
                        ch[nz][y][x] = ch[nz][ny][nx] + 1;
                    }
                }
            }
            else {
                z = nz + mz[i - 4];
                if (z >= 1 && z <= h) {
                    if (arr[z][ny][nx] == 0 && ch[z][ny][nx] == -1) {
                        q.push(make_pair(z, make_pair(ny, nx)));
                        ch[z][ny][nx] = ch[nz][ny][nx] + 1;
                    }
                }
            }
        }
    }
    for (int x = 1; x <= h; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[x][i][j] == 0&&ch[x][i][j]==-1) {
                    cout << -1 << "\n";
                    return 0;
                }
                if (ch[x][i][j] > ans) ans = ch[x][i][j];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
