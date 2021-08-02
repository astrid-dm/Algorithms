// The problem link : https://www.acmicpc.net/problem/20437
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 987654321
using namespace std;

int ans1, ans2;

void find(string s, int k){
    int arr[26] ={0,}, se[26] = {0,};
    for(int i=0; i<26; i++) se[i] = -1;
    int pos = 0, temp = 0, len = 0;
    for(int i=0; i<s.size(); i++){
        pos = s[i]-'a';
        arr[pos]++;
        if(arr[pos]==k){
            if(se[pos]==-1){
                temp = s.find(s[i]);
                se[pos] = temp;
                len = (i-se[pos])+1;
                if(ans1>len) ans1 = len;
                if(ans2<len) ans2 = len;
            }
            else{
                temp = s.find(s[i],se[pos]+1);
                se[pos] = temp;
                len = (i-se[pos])+1;
                if(ans1>len) ans1 = len;
                if(ans2<len) ans2 = len;
            }
            arr[pos]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t;
    while(t--){
        int k;
        ans1 = MAX, ans2 = 0;
        string s;
        cin >> s;
        cin >> k;
        find(s,k);
        if(ans1==MAX) cout << -1 << "\n";
        else cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
