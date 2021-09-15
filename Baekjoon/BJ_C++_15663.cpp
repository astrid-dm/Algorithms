// The problem link : https://www.acmicpc.net/submit/15663/33401474
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,temp;
vector<int> v;
vector<int> arr;
vector<bool> ch;

void nNm(int num){
    if(arr.size()==m){
        for(int i=0; i<m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int before = 0;
    for(int i=0; i<v.size(); i++){
        if(!ch[i]&&before!=v[i]){
            arr.push_back(v[i]);
            before = v[i];
            ch[i] = true;
            nNm(num+1);
            ch[i] = false;
            arr.erase(arr.begin()+num);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    ch.resize(n,false);
    sort(v.begin(),v.end());
    nNm(0);
    return 0;
}
