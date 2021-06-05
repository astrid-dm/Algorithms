// The problem link : https://www.acmicpc.net/problem/1713
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct frame{
    int number;
    int order;
    int score;
};

bool comp1(const frame &a, const frame &b){
    if(a.score==b.score) return a.order<b.order;
    else return a.score<b.score;
}

bool comp2(const frame &a, const frame &b){
    return a.number < b.number;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,s,o=1;
    cin >> n >> m;
    vector<frame> f;
    int student[101];
    for(int i=0; i<101; i++) student[i] = 0;
    for(int i=0; i<m; i++){
        cin >> s;
        student[s]++;
        if(f.size()<n){
            if(student[s]==1) f.push_back({s,o,1});
            else{
                for(int i=0; i<f.size(); i++){
                    if(f[i].number==s){
                        f[i].score++;
                        break;
                    }
                }
            }
        }
        else{
            if(student[s]==1){
                student[f[0].number] = 0;
                f[0] = {s,o,1};
            }
            else{
                for(int i=0; i<f.size(); i++){
                    if(f[i].number==s){
                        f[i].score++;
                        break;
                    }
                }
            }
        }
        o++;
        sort(f.begin(),f.end(),comp1);
    }
    sort(f.begin(),f.end(),comp2);
    for(int i=0; i<f.size(); i++) cout << f[i].number << " ";
    cout << "\n";
    return 0;
}
