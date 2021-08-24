// The problem link : https://www.acmicpc.net/problem/19583
// 12812KB, 72ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

string s,e,q,temp; // 개총시작, 개총종료, 스트리밍 종료
int s1,s2,e1,e2,q1,q2;
unordered_set<string> entry;
unordered_set<string> ans;

void input(){
    cin >> s >> e >> q;
    temp = s.substr(0,2);
    s1 = stoi(temp);
    temp = s.substr(3,5);
    s2 = stoi(temp);
    temp = e.substr(0,2);
    e1 = stoi(temp);
    temp = e.substr(3,5);
    e2 = stoi(temp);
    temp = q.substr(0,2);
    q1 = stoi(temp);
    temp = q.substr(3,5);
    q2 = stoi(temp);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    string t,n; // 시간, 이름
    while(cin >> t >> n){
        int h=0,m=0;
        temp = t.substr(0,2);
        h = stoi(temp);
        temp = t.substr(3,5);
        m = stoi(temp);
        int entry1 = (s1*100+s2), user1 = (h*100+m);
        // 입장시간 이하일 경우
        if(user1<=entry1){
            if(entry.find(n)==entry.end()) entry.insert(n);
        }
        // 종료시간 ~ 스트리망 종료시간일 경우
        int exit1 = (e1*100+e2), exit2 = (q1*100+q2), user2 = (h*100+m);
        if(user2>=exit1&&user2<=exit2){
            auto it = entry.find(n);
            auto it2 = ans.find(n);
            if(it!=entry.end()&&it2==ans.end()){
                ans.insert(n);
            }
        }
    }
    cout << ans.size() << "\n";
    return 0;
}
