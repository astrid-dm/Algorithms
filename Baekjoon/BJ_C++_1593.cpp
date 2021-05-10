#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,ans=0;
    string w,s;
    cin >> n >> m;
    cin >> w >> s;
    unordered_map<char,int> mp;
    unordered_map<char,int> mp2;
    for(int i=0; i<w.size(); i++) mp[w[i]]++;
    bool ch = true;
    int left = 0, right = n-1;
    for(int i=0; i<n; i++){
        if(mp.find(s[i])!=mp.end()) mp[s[i]]--;
        else mp2[s[i]]++;
    }
    for(auto[k,v] : mp) {
        if(v!=0) {ch = false; break;}
    }
    if(ch){
        for(auto[k,v] : mp2) {
            if(v!=0) {ch = false; break;}
        }
    }
    if(ch) ans++;
    while(n<m&&right<m){
        ch = true;
        if(mp.find(s[left])!=mp.end()) mp[s[left]]++;
        else mp2[s[left]]--;
        left++;
        right++;
        if(mp.find(s[right])!=mp.end()) mp[s[right]]--;
        else mp2[s[right]]++;
        for(auto[k,v] : mp) {
            if(v!=0) {ch = false; break;}
        }
        if(ch){
            for(auto[k,v] : mp2) {
                if(v!=0) {ch = false; break;}
            }
        }
        if(ch) ans++;
    }
    cout << ans << "\n";
    return 0;
}
