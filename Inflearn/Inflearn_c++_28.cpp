#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    int cnt1=0, cnt2=0, j=0, temp=0;
    for(int i=2; i<=n; i++){
        temp = i;
        j=2;
        while(1){
            if(temp%j==0){
                if(j==2) cnt1++;
                else if(j==5) cnt2++;
                temp=temp/j;
            }
            else j++;
            if(temp==1) break;
        }
    }
    cout << min(cnt1,cnt2) << "\n";
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
