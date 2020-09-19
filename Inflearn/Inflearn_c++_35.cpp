#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    vector<int> v1; // 양수
    vector<int> v2; // 음수
    int temp = 0;
    
    for(int i=0; i<n; i++){
        cin >> temp;
        if(temp>0) v1.push_back(temp);
        else v2.push_back(temp);
    }

    for(int i=0; i<v2.size(); i++) cout << v2[i] << " ";
    for(int i=0; i<v1.size(); i++) cout << v1[i] << " ";
    
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
