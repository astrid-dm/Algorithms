#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    int pre=0, now=0, cnt = 1, max = 1;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    pre = v[0];
    for(int i=1; i<n; i++){
        now = v[i];
        if(now>=pre){
            cnt++;
            if(cnt>max) max = cnt;
        }
        else if(now<pre) cnt = 1;
        pre = now;
    }
    cout << max << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;

    int N = 0;

    cin >> N;
    
    start = clock();
    check(N);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
