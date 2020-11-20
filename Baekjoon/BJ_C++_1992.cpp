#include <iostream>
#include <string>
using namespace std;

int n = 0;
char arr[65][65];
string ans = "";

void check(int starty, int startx, int endy, int endx) {
	int b = 0, w = 0; // b = 1로 표시된 구역
	for (int i = starty; i <= endy; i++) {
		for (int j = startx; j <= endx; j++) {
			if (arr[i][j] == '1') b++;
			else w++;
		}
	}
	if (b == 0 || w == 0) {
		if (b == 0) ans += "0";
		else ans += "1";
	}
	else {
		ans += "(";
		check(starty, startx, (starty+endy) / 2, (startx+endx) / 2); // 1사분면
		check(starty, (startx+endx)/2+1,(starty+endy)/2,endx); // 2사분면
		check((starty+endy)/2+1, startx, endy, (startx+endx)/2); // 3사분면
		check((starty + endy) / 2 + 1, (startx + endx) / 2 + 1, endy, endx); //4사분면
		ans += ")";
	}
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			arr[i][j] = c;
		}
	}
	check(1, 1, n, n);
	cout << ans << "\n";
	return 0;
}
