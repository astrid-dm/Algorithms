#include <iostream>
#include <vector>
using namespace std;

int n = 0, ans_zero = 0, ans_one = 0, ans_mone = 0, arr[2200][2200];

void check(int starty, int startx, int area) {
	int zero = 0, one = 0, mone = 0;
	for (int i = starty; i < starty+area; i++) {
		for (int j = startx; j < startx+area; j++) {
			if (arr[i][j] == 1) one++;
			else if (arr[i][j] == 0) zero++;
			else mone++;
		}
	}
	if (one == 0 && mone == 0) ans_zero++; //0으로 도배됨
	else if (zero == 0 && mone == 0) ans_one++; //1로 도배됨
	else if (zero == 0 && one == 0) ans_mone++; //-1로 도배됨
	else {
		for (int i = starty; i < starty + area; i = i + (area / 3)) {
			for (int j = startx; j < startx + area; j = j + (area / 3)) check(i, j, area / 3);
		}
	}
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	check(0, 0, n);
	cout << ans_mone << "\n" << ans_zero << "\n" << ans_one << "\n";
	return 0;
}
