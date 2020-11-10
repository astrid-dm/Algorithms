#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	while (true) {
		bool ch = false;
		string ss = "";
		getline(cin, ss);
		if (ss == ".") return 0;
		stack<char> st;
		for (int i = 0; i < ss.size(); i++) {
			if (ss[i] == '(') st.push(ss[i]);
			else if (ss[i] == '[') st.push(ss[i]);
			else if (ss[i] == ')') {
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					ch = true;
					break;
				}
			}
			else if (ss[i] == ']') {
				if (!st.empty() && st.top() == '[') st.pop();
				else {
					ch = true;
					break;
				}
			}
			else continue;
		}
		if (st.empty()&&!ch) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;
}
