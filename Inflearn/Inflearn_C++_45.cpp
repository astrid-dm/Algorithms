#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n, int m){
    vector<int> v(n+1);
    int cnt = 0, pos = 0, out = 0, res=0;
    for(int i=1; i<=n; i++) v[i] = i;
    while(out<n){
        pos++;
        if(pos>n) pos = 1;
        if(v[pos]!=0){
            cnt++;
            if(cnt==m){
                v[pos]=0;
                out++;
                res = pos;
                cnt = 0;
            }
        }
    }
    cout << res << "\n";
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;

    int N = 0, M = 0;

    cin >> N >> M;
    
    start = clock();
    check(N,M);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
