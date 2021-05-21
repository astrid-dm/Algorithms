#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, y, x, ny, nx, my[] = { 1,0,-1,0 }, mx[] = { 0,1,0,-1 }, wall, cnt;
vector<vector<int>> v;
vector<vector<vector<bool>>> ch;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char temp;
    cin >> n >> m >> k;
    v.resize(n + 1, vector<int>(m + 1));
    ch.resize(n + 1, vector<vector<bool>>(m + 1, vector<bool>(k + 1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> temp;
            v[i][j] = temp - '0';
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>>q;
    q.push({ {1,1},{0,1} });
    ch[1][1][0] = true;
    while (!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        wall = q.front().second.first;
        cnt = q.front().second.second;
        q.pop();
        if (y == n && x == m) {
            cout << cnt << "\n";
            exit(0);
        }
        for (int i = 0; i < 4; i++) {
            ny = y + my[i];
            nx = x + mx[i];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
                if (v[ny][nx] == 0 && !ch[ny][nx][wall]) {
                    ch[ny][nx][wall] = true;
                    q.push({ {ny,nx},{wall,cnt + 1} });
                }
                else if (v[ny][nx] == 1 && wall < k && !ch[ny][nx][wall + 1]) {
                    ch[ny][nx][wall + 1] = true;
                    q.push({ {ny,nx},{wall + 1,cnt + 1} });
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
