// The problem link : https://www.acmicpc.net/problem/20922
// 3068kb, 20ms
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0, k=0,le=0,ri=0,len=1,arr[MAX] = {0,};
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<MAX; i++) arr[i] = 0;
    while(le<=ri&&ri<n){
        if(arr[v[ri]]+1<=k){
            arr[v[ri]]++;
            len = max(len,ri-le+1);
            ri++;
        }else{
            arr[v[le]]--;
            le++;
        }
    }
    cout << len << "\n";
    return 0;
}
