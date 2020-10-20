#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m = 0, n = 0, k = 0, my = 0, mx = 0 ,width = 0;
bool ch[102][102] = { false, };
int yy[4] = { 0,1,0,-1 };
int xx[4] = { 1,0,-1,0 };

void dfs(int y, int x) {
	ch[y][x] = true;
	width++;
	for (int i = 0; i < 4; i++) {
		my = y + yy[i];
		mx = x + xx[i];
		if (my >= 0 && my < m && mx >= 0 && mx < n) {
			if (!ch[my][mx]) dfs(my, mx);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int y1 = 0, x1 = 0, y2 = 0, x2 = 0;
	vector<int> v;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int a = y1; a < y2; a++) {
			for (int b = x1; b < x2; b++) {
				ch[a][b] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!ch[i][j]) {
				width = 0;
				dfs(i, j);
				v.push_back(width);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	return 0;
}
