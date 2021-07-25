// The problem link : https://www.acmicpc.net/problem/2493
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    cin >> n;
    stack<pair<int,int>> st;
    vector<int> tower(n+1);
    vector<int> ans(n+1);
    for(int i=1; i<=n; i++) {
        cin >> tower[i];
        while(!st.empty()){
            if(st.top().first<tower[i]) st.pop();
            else break;
        }
        if(st.empty()){
            ans[i] = 0;
        }
        else ans[i] = st.top().second;
        st.push({tower[i],i});
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
