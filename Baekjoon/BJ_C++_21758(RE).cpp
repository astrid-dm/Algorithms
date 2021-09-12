// The problem link : https://www.acmicpc.net/problem/21758
// 100점, 2412KB, 12ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define MAX 987654321
 
using namespace std;
int ans = 0, n = 0;

void go(vector<int> &v, int t){
    int temp = 0, num = 0, temp2 = 0, first_sum= 0, second_sum = 0, mid = 0, total = 0;
    if(t==0){ // 꿀이 첫번째, 벌 하나는 마지막
        for(int i=0; i<n-1; i++) temp += v[i]; 
        temp2 = temp;
        first_sum = temp;
        second_sum = temp;
        for(int i=n-2; i>=1; i--){
            first_sum-=v[i];
            second_sum-=v[i];
            if(mid==0) mid = v[i];
            else{
                first_sum += mid;
                mid = v[i];
            }
            if(first_sum+second_sum>total){
                temp = first_sum+second_sum;
                total = temp;
            }
        }
    }else if(t==1){
        for(int i=1; i<n-1; i++){
            temp += v[i];
            if(v[i]>num) num = v[i];
        }
        temp += num;
    }else{ // 꿀이 마지막, 벌 하나는 첫번째
        for(int i=1; i<n; i++) temp += v[i]; 
        temp2 = temp;
        first_sum = temp;
        second_sum = temp;
        for(int i=1; i<n-1; i++){
            first_sum-=v[i];
            second_sum-=v[i];
            if(mid==0) mid = v[i];
            else{
                first_sum += mid;
                mid = v[i];
            }
            if(first_sum+second_sum>total){
                temp = first_sum+second_sum;
                total = temp;
            }
        }
    }
    if(ans<temp) ans = temp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    go(v,0); // honey bee bee
    go(v,1); // bee honey bee
    go(v,2); // bee bee boney
    cout << ans << "\n";
    return 0;
}
