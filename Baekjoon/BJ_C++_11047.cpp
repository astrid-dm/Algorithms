#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, k = 0, arr[11], total = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	while (n > 0&&k!=0) {
		if (k >= arr[n]) {
			k -= arr[n];
			total++;
		}
		else n--;
	}
	cout << total << "\n";

	return 0;
}
