\#include <iostream>
using namespace std;

bool ch[11] = {false,};
int n = 0, ans = 1e9;
int v[10][10];

void go(int start, int index, int cnt, int sum){
	if(cnt==n){
		if(v[index][start]==0) return; // 중요
		if(ans>sum+v[index][start]) ans = sum+v[index][start];
		return;
	}
	for(int i=0; i<n; i++){
		if(ch[i]||v[index][i]==0) continue;
		ch[i] = true;
		go(start,i,cnt+1,sum+v[index][i]);
		ch[i] = false;
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
	for(int i=0; i<n; i++){
		ch[i] = true;
		go(i,i,1,0); // 최초 출발지점, 현재 위치, 지나간 마을수, 이동비용
		ch[i] = false;
	}
	cout << ans << "\n";
	return 0;
}
