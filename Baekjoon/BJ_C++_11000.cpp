#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0, c = 0, d = 0;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c >> d;
        v.push_back(make_pair(c,d));
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for(int i=1; i<n; i++){
        if(pq.top()<=v[i].first) pq.pop(); // 강의실 1개로 나눠쓸수 있는거면 pop
        pq.push(v[i].second);
    }
    cout << pq.size() << "\n";
   return 0;
}
