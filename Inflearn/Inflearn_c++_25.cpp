#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    int a[100] = {0,};
    int b[100] = {0,};

    for(int i=0; i<100; i++){
        cin >> a[i];
        b[i] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[j]>a[i]) b[i]++;
        }
    }
    for(int i=0; i<n; i++){
        cout << b[i] << " ";
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
