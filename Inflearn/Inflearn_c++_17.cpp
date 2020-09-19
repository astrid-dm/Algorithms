#include <iostream>
#include <ctime>

using namespace std;

int check(int n){
    for(int i=0; i<n; i++){
        int a = 0;
        int ans = 0;
        cin >> a >> ans;
        if(ans==(a*(a+1))/2) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;
    
    int n = 0;
    cin >> n;
    
    start = clock();
    check(n);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
