#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, max = 0;
	cin >> n;
  int *sum = new int[n];
	vector<pair<int,int>> v;
	for(int i=0; i<n; i++){
		int a, b = 0;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	for(int i=0; i<n; i++) sum[i] = 1;
	sort(v.begin(), v.end());
	for(int i=1; i<v.size(); i++){
		for(int j=0; j<i; j++){
			if(v[i].second>v[j].second){
				if(sum[i]<sum[j]+1) sum[i] = sum[j]+1;
			}
		}
	}
	for(int i=0; i<v.size(); i++){
		if(sum[i]>max) max = sum[i];
	}
	cout << v.size()-max << "\n";
	return 0;
}
