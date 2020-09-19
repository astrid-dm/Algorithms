#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    int temp = 0, cnt = 0, digit = 0;
    for(int i=1; i<=n; i++){
        temp = i;
        while(temp>0){
            digit=temp%10;
            if(digit==3) cnt++;
            temp=temp/10;
        }
    }
    cout << cnt << "\n";
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
