#include <iostream>
#include <vector> // 동적할당
using namespace std;

void check(int n, int k){
    vector<int> a(k);
    int sum = 0;
    int max = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<k; i++){
        sum+=a[i];
    }
    max = sum;
    for(int i=k; i<n; i++){
        sum = sum + (a[i]-a[i-k]);
        if(sum>max) max = sum;
    }
    cout << max << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;

    int N = 0;
    int K = 0;

    cin >> N >> K;
    
    start = clock();
    check(N,K);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
