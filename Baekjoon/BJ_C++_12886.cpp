// The problem link : https://www.acmicpc.net/problem/12886
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool ch[1501][1501];

void check(int a, int b, int c){
    ch[a][b] = true;
    ch[b][a] = true;
    ch[b][c] = true;
    ch[c][b] = true;
    ch[a][c] = true;
    ch[c][a] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c, aa, bb, cc;
    cin >> a >> b >> c;
    check(a,b,c);
    queue<pair<pair<int, int>, int>> q;
    q.push({ {a,b},c });
    if ((a + b + c) % 3 == 0) {
        while (!q.empty()) {
            aa = q.front().first.first;
            bb = q.front().first.second;
            cc = q.front().second;
            q.pop();
            if (aa == bb && bb == cc) {
                cout << 1 << "\n";
                exit(0);
            }
            if (aa != bb && aa<=1000 && bb<=1000) {
                a = min(aa, bb);
                b = max(aa, bb);
                c = cc;
                b -= a;
                a += a;
                if (!ch[a][b]&&!ch[b][a]) {
                    ch[a][b] = true;
                    ch[b][a] = true;
                    q.push({ { a,b }, c });
                }
            }
            if (aa != cc && aa<=1000 && cc<=1000) {
                a = min(aa, cc);
                c = max(aa, cc);
                b = bb;
                c -= a;
                a += a;
                if (!ch[a][c]&&!ch[c][a]){
                    q.push({ { a,b }, c });
                    ch[a][c] = true;
                    ch[c][a] = true;
                }
            }
            if (bb != cc && bb<=1000 && cc<=1000) {
                a = aa;
                b = min(bb, cc);
                c = max(bb, cc);
                c -= b;
                b += b;
                if (!ch[b][c]&&!ch[c][b]){
                    q.push({ { a,b }, c });
                    ch[b][c] = true;
                    ch[c][b] = true;
                }
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}
