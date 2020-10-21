#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n = 0, k = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	queue<int> q;
	int cnt = 1, temp = 0;
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty()) {
		if (cnt == k) {
			temp = q.front();
			q.pop();
			cnt = 1;
		}
		else {
			cnt++;
			temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	cout << temp << "\n";
	return 0;
}
