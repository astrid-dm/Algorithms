#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int n = 0, arr[1001], ans = 0;
	cin >> n; 
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			ans += arr[j];
		}
	}
	cout << ans << "\n";

	return 0;
}
