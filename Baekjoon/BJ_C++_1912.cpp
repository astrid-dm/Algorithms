#include <iostream>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int arr[100001];
int sum[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, maxi = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum[i] = arr[i];
	}
	maxi = sum[0];
	for (int i = 1; i < n; i++) {
		sum[i] = max(arr[i], sum[i - 1] + sum[i]);
		if (maxi < sum[i]) maxi = sum[i];
	}
	cout << maxi << "\n";
	return 0;
}
