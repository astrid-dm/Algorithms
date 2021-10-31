// The problem link : https://www.acmicpc.net/problem/1436
// The result : 2020KB, 68ms
#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned long long cnt = 665;
    int ans = 0, temp = 0;
    cin >> temp;
    while (true) {
        string s = to_string(cnt);
        if (s.find("666")!=s.npos) ans++;
        if (ans == temp) {
            cout << s << "\n";
            break;
        }
        cnt++;
    }
    return 0;
}
