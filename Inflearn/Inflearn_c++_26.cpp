#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    vector<int> v(n);
    int cnt = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << "1 ";
    for(int i=1; i<n; i++){
        cnt = 1;
        for(int j=0; j<i; j++){
            if(v[j]>=v[i]) cnt++;
        }
        cout << cnt << " ";
    }
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
