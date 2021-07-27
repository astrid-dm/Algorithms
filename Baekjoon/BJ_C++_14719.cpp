// The problem link : https://www.acmicpc.net/problem/14719
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int h,w,pos=0,ans=0,next=0,pillar=0;
    cin >> h >> w;
    vector<int> v(w);
    for(int i=0; i<w; i++) cin >> v[i];
    for(int i=0; i<w; i++){
        if(v[i]==0) continue;
        stack<int> st;
        st.push(v[i]);
        for(int j=i+1; j<w; j++){
            st.push(v[j]);
            next = j;
            if(v[i]<=v[j]) break;
        }
        if(v[i]>st.top()) pillar = st.top(); // 맨 왼쪽 기둥보다 큰 기둥을 발견 못한 경우
        else pillar = v[i];
        st.pop();
        while(!st.empty()){
            pos = st.top();
            if(pos>pillar) pillar = pos;
            if(pillar-pos>0) ans+=pillar-pos;
            st.pop();
        }
        if(next==w-1) break;
        else i=next-1;
    }
    cout << ans << "\n";
    return 0;
}
