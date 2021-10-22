// The problem link : https://www.acmicpc.net/problem/16508
// The result : 2024KB, 8ms
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;

int goal[26], alphabet[26], cnt, ans = MAX;
vector<pair<int, string>> v;

void input() {
    int price;
    string minho,title;
    cin >> minho;
    for (auto i : minho) goal[i - 'A']++;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
        cin >> price >> title;
        v.push_back({ price,title });
    }
}

bool check() {
    for (int i = 0; i < 26; i++) {
        if (goal[i] > alphabet[i]) return false;
    }
    return true;
}

void comb(int book, int priceSum) {
    if (book >= cnt) {
        if (check()) ans = min(ans, priceSum);
        return;
    }
    string temp = v[book].second;
    for (auto i : temp) alphabet[i - 'A']++;
    comb(book + 1, priceSum + v[book].first);
    for (auto i : temp) alphabet[i - 'A']--;
    comb(book + 1, priceSum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    comb(0, 0);
    if (ans == MAX) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
