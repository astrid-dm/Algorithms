#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	
	int test;
	cin >> test;
	while (test > 0) {
		string s1 = "", s2 = "", stemp ="";
		int num = 0, temp = 0, temp2 = 0;
		bool ch = false, end = false;
		deque<int>q;
		cin >> s1;
		cin >> num;
		cin >> s2;
		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] >= '0' && s2[i] <= '9') temp2 = (temp2 * 10) + (s2[i] - 48);
			else{
				if (temp2 != 0) {
					q.push_front(temp2);
					temp2 = 0;
				}
			}
		}
		for (int i = 0; i < s1.size(); i++) {
			if (q.empty()&&s1[i]=='D') {
				end = true;
				break;
			}
			else {
				if (s1[i] == 'R') ch = !ch; //ch가 true면 reverse상태
				else if(s1[i]=='D') {
					if (ch) q.pop_front();
					else q.pop_back();
				}
			}
		}
		if (!q.empty()) {
			cout << "[";
			if (ch) {
				while (!q.empty()) {
					if (q.size() == 1) cout << q.front() << "]" << "\n";
					else cout << q.front() << ',';
					q.pop_front();
				}
			}
			else {
				while (!q.empty()) {
					if (q.size() == 1) cout << q.back() << "]" << "\n";
					else cout << q.back() << ',';
					q.pop_back();
				}
			}
		}
		else { 
			if (!end)cout << "[]" << "\n";
			else cout << "error" << "\n";
		}
		test--;
	}
	return 0;
}
