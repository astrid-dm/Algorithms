#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int n = 0, m = 0, cnt = 0, temp = 0, temp2 = 0, ans = 0, arr[50];
	queue<int>q;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) q.push(i);
	while (cnt < m) {
		if (q.front() == arr[cnt]) {
			q.pop();
			cnt++;
		}
		else {
			temp = 0;
			while (q.front() != arr[cnt]) {
				temp2 = q.front();
				q.pop();
				q.push(temp2);
				temp++;
			}
			if (temp > q.size() / 2) ans += q.size() - temp;
			else ans += temp;
		}
	}
	cout << ans << "\n";
	return 0;
}
