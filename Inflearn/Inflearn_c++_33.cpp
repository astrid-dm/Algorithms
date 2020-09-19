#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool des(int a, int b){
    return a>b;
}

void check(int n){
    vector<int> v(n);
    int rank = 1;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), des);
    for(int i=1; i<n; i++){
        if(v[i]!=v[i-1]){
            rank++;
            if(rank==3){
                cout << v[i] << "\n";
                return;
            }
        }
    }
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;

    int N;

    cin >> N;
    
    start = clock();
    check(N);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
