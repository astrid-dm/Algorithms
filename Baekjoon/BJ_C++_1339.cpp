#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n=0;
unsigned long long maxi = 0;
char alphas[256];

int comp(vector<string> &origin, vector<char> &letters, vector<int> &nums){
	int res = 0; 
	for(int i=0; i<nums.size(); i++){
		alphas[letters[i]] = nums[i];
	}
	for(string s : origin){
		int now = 0;
		for(char c : s){
			now*=10;
			now+=alphas[c];
		}
		res += now;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<string> v(n); // 원본
	vector<char> letters; //원본 알파벳 단어만 저장
	vector<int> nums; // 사용할 숫자를 저장
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		v.push_back(s);
		for(char a : s) letters.push_back(a);
	}
	sort(letters.begin(), letters.end()); 
	letters.erase(unique(letters.begin(),letters.end()),letters.end()); // unique를 쓰기위해 sort는 필수
	int m = letters.size(); 
	for(int i=9; i>9-m; i--){
		nums.push_back(i);
	}
	sort(nums.begin(), nums.end());
	do{
		int temp = comp(v, letters, nums);
		if(maxi<temp) maxi = temp;
	}while(next_permutation(nums.begin(), nums.end()));
	cout << maxi << "\n";
	return 0;
}
