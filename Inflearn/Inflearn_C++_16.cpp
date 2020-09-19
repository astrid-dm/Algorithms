#include <iostream>
#include <ctime>

using namespace std;

bool check (string a, string b){
    int arr1[52] = {0,};
    int arr2[52] = {0,};
    
    for(int i=0; i<a.size(); i++){
        if(a[i]>='A'&&a[i]<='Z'){
            arr1[a[i]-65]++;
        }
        else if(a[i]>='a'&&a[i]<='z'){
            arr1[a[i]-71]++;
        }
    }
    for(int i=0; i<b.size(); i++){
        if(b[i]>='A'&&b[i]<='Z'){
            arr2[b[i]-65]++;
        }
        else if(b[i]>='a'&&b[i]<='z'){
            arr2[b[i]-71]++;
        }
    }
    
    for(int i=0; i<52; i++){
        if(arr1[i]==arr2[i]){
            if(i==51) {
                cout << "YES" << "\n";
                return true;
            }
        }
        else break;
    }
    cout << "NO" << "\n";
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;
    
    string a = "";
    string b = "";
    
    cin >> a;
    cin >> b;
    
    start = clock();
    cout << check(a,b);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
