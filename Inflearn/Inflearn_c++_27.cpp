#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    vector<int> v(n+1);
    int temp = 0, j=0;
    for(int i=2; i<=n; i++){
        temp = i;
        j=2;
        while(1){
            if(temp%j==0){
                temp = temp/j;
                v[j]++;
            }
            else j++;
            if(temp==1) break;
        }
    }
    cout << n << "!" << " = ";
    for(int i=2; i<=n; i++){
        if(v[i]!=0) cout << v[i] << " ";
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
