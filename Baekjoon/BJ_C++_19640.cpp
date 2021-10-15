// The problem link : https://www.acmicpc.net/problem/19640
// The result : 95316KB, 180ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct wc {
    int d;
    int h;
    int g;
    int c;
};

struct comp {
    bool operator()(wc& a, wc& b) {
        if (a.d != b.d) return a.d < b.d;
        else if (a.h != b.h) return a.h < b.h;
        else return a.g > b.g;
    }
};

int n, m, k, a, b, ans;
vector<wc> people;
vector<queue<wc>> lines;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k; // n : 사원수, m : 줄의 수, k : 데카의 앞에 있던 사람 수 
    priority_queue<wc, vector<wc>, comp> pq;
    for (int i = 0; i < m; i++) {
        queue<wc> q;
        lines.push_back(q);
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        lines[i % m].push({ a,b,i % m,i });
    }
    for (int i = 0; i < m; i++) {
        if (lines[i].empty()) continue;
        pq.push(lines[i].front());
        lines[i].pop();
    }
    while (true) {
        if (pq.top().c == k) break;
        int pos = pq.top().g;
        pq.pop();
        ans++;
        if (lines[pos].empty()) continue;
        pq.push(lines[pos].front());
        lines[pos].pop();
    }
    cout << ans << "\n";
    return 0;
}
