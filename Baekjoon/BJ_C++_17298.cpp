// The problem link : https://www.acmicpc.net/problem/17298
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0,temp=0,now=0;
    stack<int> st;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n);
    int pos = n-2;
    for (int i = 0; i < n; i++) cin >> v[i];
    st.push(v[v.size() - 1]);
    ans[n-1] = -1;
    while (pos>=0) {
        temp = st.top();
        now = v[pos];
        if (temp > now) {
            ans[pos] = temp;
            st.push(now);
        }
        else {
            while (!st.empty()) {
                temp = st.top();
                if (temp <= now) st.pop();
                else {
                    ans[pos] = st.top();
                    break;
                }
            }
            if (st.empty()) ans[pos] = -1;
            st.push(now);
        }
        pos--;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
