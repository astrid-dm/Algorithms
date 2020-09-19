#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    vector<int> arr(n);
    vector<bool> jolly(n-1);
    int pre = 0, now = 0, temp = 0;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    pre = arr[0];
    
    for(int i=1; i<n; i++){
        now = arr[i];
        temp = abs(pre-now);
        if(temp>0&&temp<n&&jolly[temp]==false) jolly[temp] = true;
        else {
            cout << "NO" << "\n";
            return;
        }
        pre = now;
    }
    cout << "YES" << "\n";
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
