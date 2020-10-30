#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int n = 0, a = 0, b = 0, ans = 1;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	a = v[0].first;
	for (int i = 1; i < n; i++) {
		if (a <= v[i].second) {
			ans++;
			a = v[i].first;
		}
	}
	cout << ans << "\n";
}
