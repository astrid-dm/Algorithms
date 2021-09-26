// The problem link : https://www.acmicpc.net/problem/5002
// The result : 2024KB, 0ms
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// M M // M M W W M W = 14 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, man = 0, woman = 0, pos = 0;
    queue<char> q;
    string temp;
    cin >> x;
    cin >> temp;
    while(pos<temp.size()){
        char c = temp[pos];
        if(!q.empty()){
            char waiting = q.front();
            if(waiting=='M'){
                if(abs((man+1)-woman)<=x){
                    man++;
                    q.pop();
                }
            }else{
                if(abs(man-(woman+1))<=x){
                    woman++;
                    q.pop();
                }
            }
        }
        if(c=='M'){
            if(abs((man+1)-woman)<=x) man++;
            else if(q.empty()) q.push(c);
            else break;
        }else{
            if(abs(man-(woman+1))<=x) woman++;
            else if(q.empty()) q.push(c);
            else break;
        }
        pos++;
    }
    cout << woman+man << "\n";
    return 0;
}
