#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testNum;
	cin >> testNum;
	while(testNum--){
		int applNum, resumeRank, interviewRank, ans = 1, bigRank;
		cin >> applNum;
		vector<pair<int,int>> v(applNum);
		for(int i=0; i<applNum; i++){
			cin >> resumeRank >> interviewRank;
			v[i] = {resumeRank, interviewRank};
		}
		sort(v.begin(),v.end());
		bigRank = v[0].second;
		for(int i=1; i<applNum; i++){
			if(v[i].second<bigRank) {
				ans++;
				bigRank = v[i].second;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
