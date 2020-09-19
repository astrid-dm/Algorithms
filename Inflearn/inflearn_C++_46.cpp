#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    vector<int> v(n+1);
    int bo = 0, sec = 0, pos = 0, tot = 0;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        tot += v[i];
    }
    cin >> bo;
    if(bo>=tot){
        cout << -1 << "\n";
        return;
    }
    while(1){
        pos++;
        if(pos>n) pos=1;
        if(v[pos]==0) continue;
        v[pos]--;
        sec++;
        if(sec==bo) break;
    }
    while(1){
        pos++;
        if(pos>n) pos=1;
        if(v[pos]!=0) break;
    }
    cout << pos << "\n";
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin >> N;
    
    check(N);

    return 0;
}
