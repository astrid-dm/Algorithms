#include <iostream>
#include <algorithm>
#include <vector>
const int MAX = 12;
using namespace std;

int n = 0, ans = -1e4, temp = 0;

void bt(vector<int> &v, int num){
    if(v.size()<=2){
        if(num>ans) ans = num;
        return;
    }
    for(int i=1; i<v.size()-1; i++){
        vector<int> samp = v;
        temp = v[i-1]*v[i+1];
        samp.erase(samp.begin()+i);
        bt(samp,num+temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    bt(v,0);
    cout << ans << "\n";
    return 0;
}
