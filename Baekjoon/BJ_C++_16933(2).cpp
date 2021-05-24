// The problem link : https://www.acmicpc.net/problem/16933
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, yy, xx, ww, cc, dayornight, my[] = { 0,1,0,-1 }, mx[] = { 1,0,-1,0 }, ny, nx;

struct go {
    int y, x;
    int wall, cnt;
    int day; // 0 = day, 1 = night
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    vector <vector<char>> v(n+1, vector<char>(m+1, 0));
    vector<vector<vector<bool>>> ch(n + 1, vector<vector<bool>>(m + 1, vector<bool>(k+1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> v[i][j];
    }
    queue<go> q;
    q.push({ 1,1,0,1,0 }); // 구조체니까 중괄호 하나 안에 한번에 모든 원소 입력
    ch[1][1][0] = true;
    while (!q.empty()) {
        yy = q.front().y;
        xx = q.front().x;
        ww = q.front().wall;
        cc = q.front().cnt;
        dayornight = q.front().day;
        q.pop();
        if (yy == n && xx == m) {
            cout << cc << "\n";
            exit(0);
        }
        for (int i = 0; i < 4; i++) {
            ny = yy + my[i];
            nx = xx + mx[i];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
                if (v[ny][nx] == '0' && !ch[ny][nx][ww]) { // 통로
                    ch[ny][nx][ww] = true;
                    q.push({ ny,nx,ww,cc + 1,abs(dayornight - 1) });
                }
                else if (v[ny][nx] == '1' && dayornight==0 && ww < k && !ch[ny][nx][ww + 1]) { // 벽 (낮)
                    ch[ny][nx][ww+1] = true;
                    q.push({ ny,nx,ww + 1,cc + 1,abs(dayornight - 1) });
                }
                else if (v[ny][nx] == '1' && dayornight == 1 && ww < k && !ch[ny][nx][ww + 1]) q.push({ yy,xx,ww,cc + 1,abs(dayornight - 1) });// 벽 (밤)
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
