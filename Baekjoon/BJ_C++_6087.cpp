// The problem link : https://www.acmicpc.net/problem/6087
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1e9
using namespace std;

int w, h, s1, s2, d1, d2, exm, m, y, x, exnm, nm, ny, nx, my[] = { 1,0,-1,0 }, mx[] = { 0,1,0,-1 };
vector<vector<char>> v;
vector<vector<int>> map;
typedef pair<pair<int,int>, pair<int, int>> r;
bool ch[101][101];

void bfs() {
    queue<r> q;
    q.push({ {-1,-1},{s1,s2} });
    ch[s1][s2] = true;
    map[s1][s2] = -1;
    while (!q.empty()) {
        exm = q.front().first.first;
        m = q.front().first.second;
        y = q.front().second.first;
        x = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + my[i];
            nx = x + mx[i];
            nm = m;
            if (i != exm) nm++;
            if (ny > 0 && ny <= h && nx > 0 && nx <= w && v[ny][nx]!='*') {
                if (!ch[ny][nx] || map[ny][nx] >= nm) {
                    ch[ny][nx] = true;
                    map[ny][nx] = nm;
                    q.push({ {i,nm},{ny,nx} });
                }
            }
        }
    }
}

void input() {
    int temp = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'C' && temp == 0) {
                s1 = i, s2 = j;
                temp++;
            }
            else if (v[i][j] == 'C' && temp > 0) d1 = i, d2 = j;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) map[i][j] = MAX;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h;
    v.resize(h + 1, vector<char>(w + 1));
    map.resize(h + 1, vector<int>(w + 1));
    input();
    bfs();
    cout << map[d1][d2] << "\n";
    return 0;
}
