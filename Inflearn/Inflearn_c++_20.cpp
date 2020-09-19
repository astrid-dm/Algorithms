#include <iostream>
using namespace std;

void check (int n){
    int a[10] = {0,};
    int asum = 0;
    int b[10] = {0,};
    int bsum = 0;

    for(int i=0; i<10; i++){
        cin >> a[i];
    }
    for(int i=0; i<10; i++){
        cin >> b[i];
    }
    for(int i=0; i<10; i++){
        if(a[i]>b[i]) asum+=3;
        else if(a[i]<b[i]) bsum+=3;
        else{asum+=1; bsum+=1;}
    }
    
    cout << asum << " " << bsum << "\n";

    if(asum>bsum){
        cout << "A" << "\n";
        return;
    }
    else if(asum<bsum){
        cout << "B" << "\n";
        return;
    }
    else{
        for(int i=9; i>=0; i--){
            if(a[i]>b[i]){
                cout << "A" << "\n";
                return;
            }
            else if(a[i]<b[i]){
                cout << "B" << "\n";
                return;
            }
        }
    }
    cout << "D" << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;
    
    start = clock();
    check(10);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
