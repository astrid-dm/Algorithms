// The problem link : https://www.acmicpc.net/problem/19942
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1e9
using namespace std;

struct food{
    int a,b,c,d,e;
};

int n,c1,c2,c3,c4,money=MAX,temp[16],ans_len=0,ans[16];
bool ch[16];
vector<food> v(16);

void calculate(int len){
    int t1=0,t2=0,t3=0,t4=0,t5=0;
    for(int i=1; i<=len; i++){
        t1 += v[temp[i]].a;
        t2 += v[temp[i]].b;
        t3 += v[temp[i]].c;
        t4 += v[temp[i]].d;
        t5 += v[temp[i]].e;
    }
    if(t1>=c1&&t2>=c2&&t3>=c3&&t4>=c4&&money>t5){
        money = t5;
        for(int i=1; i<=len; i++){
            ans[i] = temp[i];
        }
        ans_len = len;
    }
    return;
}

void bt(int cnt, int order){
    for(int i=cnt; i<=n; i++){
        if(!ch[i]){
            ch[i] = true;
            temp[order] = i;
            calculate(order);
            bt(temp[order],order+1);
            ch[i] = false;
        }
    }
    return;
}

void input(){
    cin >> n;
    cin >> c1 >> c2 >> c3 >> c4;
    for(int i=1; i<=n; i++){
        cin >> v[i].a;
        cin >> v[i].b;
        cin >> v[i].c;
        cin >> v[i].d;
        cin >> v[i].e;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    bt(1,1);
    if(ans_len>0){
        cout << money << "\n";
        for(int i=1; i<=ans_len; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    else cout << -1 << "\n";
    return 0;
}
