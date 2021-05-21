// The problem link : https://www.acmicpc.net/problem/16933
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int n, m, k, y, x, ny, nx, my[] = { 1,0,-1,0 }, mx[] = { 0,1,0,-1 }, wall, cnt, day;
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
    queue<tuple<pair<pair<int, int>, pair<int, int>>, int>>q;
    q.push({ {{1,1},{0,1}},0 });
    ch[1][1][0] = true;
    while (!q.empty()) {
        y = get<0>(q.front()).first.first;
        x = get<0>(q.front()).first.second;
        wall = get<0>(q.front()).second.first;
        cnt = get<0>(q.front()).second.second;
        day = get<1>(q.front()); // day = 0 = day, day = 1 = night
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
                    q.push({ {{ny,nx},{wall,cnt + 1} },abs(day - 1) });
                }
                else if (v[ny][nx] == 1 && wall < k && day == 0 && !ch[ny][nx][wall + 1]) {
                    ch[ny][nx][wall + 1] = true;
                    q.push({ {{ny,nx},{wall + 1,cnt + 1} },abs(day - 1) });
                }
                else if (v[ny][nx] == 1 && wall < k && day == 1 && !ch[ny][nx][wall + 1]) {
                    q.push({ {{y,x},{wall,cnt + 1} },abs(day-1) });
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
