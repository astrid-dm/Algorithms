#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000
using namespace std;

int arr[MAX], v[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    bool ch = false, done = false;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i]; // 찾아야하는 원본
        v[i] = arr[i];
    }
    do{
        if(ch){
            for(int i=0; i<n; i++){
                cout << v[i] << " ";
            }
            done = true;
            break;
        }
        for(int i=0; i<n; i++){
            if(v[i]==arr[i]) ch = true;
            else{
                ch = false;
                break;
            }
        }
    }while(prev_permutation(v,v+n));
    if(!done) cout << -1 << "\n";
    return 0;
}
