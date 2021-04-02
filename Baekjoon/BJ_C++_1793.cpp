#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ans[251];

void tile(int n) {
	for (int i = 4; i <= n; i++) {
		string temp = "", n1 = ans[i - 1], n2 = ans[i - 2], n3 = ans[i - 2];
		int sum = 0;
		while (!n1.empty() || !n2.empty() || !n3.empty() || sum) { // while(sum)은 sum!=0과 같은 뜻
			if (n1 != "") {
				sum += n1.back() - '0';
				n1.pop_back();
			}
			if (n2 != "") {
				sum += n2.back() - '0';
				n2.pop_back();
			}
			if (n3 != "") {
				sum += n3.back() - '0';
				n3.pop_back();
			}
			temp.push_back((sum % 10) + '0');
			sum /= 10;
		}
		reverse(temp.begin(), temp.end());
		ans[i] = temp;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ans[0] = '1', ans[1] = '1', ans[2] = '3', ans[3] = '5'; // 주의. ans[0] = 1이다!
	string n = "";
	while (cin >> n) { // 입력값이 계속 주어지는 한 while은 멈추지 않음
		int temp = stoi(n);
		if (ans[temp]!="") cout << ans[temp] << "\n";
		else {
			tile(temp);
			cout << ans[temp] << "\n";
		}
	}
	return 0;
}
BAEKJOON(백준) 1107 : Brute Force (C++)
