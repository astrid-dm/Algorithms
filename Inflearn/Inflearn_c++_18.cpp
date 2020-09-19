#include <iostream>
#include <ctime>

using namespace std;

int check(int n, int m){
    int temp = 0; int maxi = 0;
    for(int i=0; i<n; i++){
        int a = 0;
        cin >> a;
        if(a>=m) temp++;
        else{
            maxi = max(temp,maxi);
            temp = 0;
        }
    }
    cout << maxi << "\n";
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;
    
    int n = 0; int m = 0;
    cin >> n >> m;
    
    start = clock();
    check(n,m);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
