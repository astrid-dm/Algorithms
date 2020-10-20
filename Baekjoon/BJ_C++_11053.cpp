#include <iostream>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int arr[1001];
int sum[1001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, temp = 0, top = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		temp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (sum[i] < sum[j] + 1) sum[i] = sum[j] + 1;
			}
		}
		if (top < sum[i]) top = sum[i];
	}
	cout << top << "\n";
	return 0;
}
