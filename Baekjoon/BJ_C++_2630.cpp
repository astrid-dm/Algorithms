#include <iostream>
using namespace std;

int n = 0, arr[129][129], wh = 0, bl = 0;

void check(int starty, int startx, int endy, int endx) {
	int white = 0, blue = 0;
	for (int i = starty; i <= endy; i++) {
		for (int j = startx; j <= endx; j++) {
			if (arr[i][j] == 0) white++;
			else blue++;
		}
	}
	if (blue == 0||white==0) {
		if (blue == 0) wh++;
		else bl++;
	}
	else {
		check(starty, startx, (starty+endy) / 2, (startx+endx) / 2); // 1사분면
		check(starty, (startx+endx)/2+1,(starty+endy)/2,endx); // 2사분면
		check((starty+endy)/2+1, startx, endy, (startx+endx)/2); // 3사분면
		check((starty + endy) / 2 + 1, (startx + endx) / 2 + 1, endy, endx); //4사분면
	}
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}
	check(1, 1, n, n);
	cout << wh << "\n" << bl << "\n";
	return 0;
}
