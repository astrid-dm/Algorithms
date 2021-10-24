// The problem link : https://www.acmicpc.net/problem/19941
// The result : 2168KB, 0ms
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,k,ans=0;
	string s;
	cin >> n >> k;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='P'){
			for(int j=i-k; j<=i+k; j++){
				if(i<0||i>=n) continue;
				if(s[j]=='H'){
					ans++;
					s[j] = 'X';
					break;
				}
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
