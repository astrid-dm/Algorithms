#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int k = 0;
pair<string,long long> maxi = {"",-9876543210}; pair<string,long long> mini = {"", 9876543210};
bool ch[10] = {false,};
char c, arr[] = {'0','1','2','3','4','5','6','7','8','9'};
vector<char> v;

void bt(string tx, int index){
    if(tx.size()>k){
        long long temp = stoll(tx);
        if(temp>=maxi.second) maxi = {tx,temp}; 
        if(temp<=mini.second) mini = {tx,temp};
        return; 
    }
    for(int i=0; i<10; i++){
        if(!ch[i]){
            if(index==0){
                ch[i] = true;
                bt(tx+arr[i],index+1);
                ch[i] = false;
            }
            else{
                if(v[index-1]=='>'&&tx[index-1]>arr[i]){
                    ch[i] = true;
                    bt(tx+arr[i],index+1);
                    ch[i] = false;
                }
                else if(v[index-1]=='<'&&tx[index-1]<arr[i]){
                    ch[i] = true;
                    bt(tx+arr[i],index+1);
                    ch[i] = false;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> c;
        v.push_back(c);
    }
    bt("", 0);
    cout << maxi.first << "\n" << mini.first<< "\n";
    return 0;
}
