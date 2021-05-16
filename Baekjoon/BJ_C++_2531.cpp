#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,d,k,c,temp,ans=0;
    cin >> n >> d >> k >> c;
    vector<int> v(n*2+1);
    vector<bool> ch(d+1);
    for(int i=0; i<=d; i++) ch[i] = false;
    for(int i=1; i<=n; i++){
        cin >> temp;
        v[i] = temp;
        v[i+n]= temp;
    }  
    int left=1, right = 1, num = 1;
    ch[v[left]] = true;
    while(right<=n+k-1){
        right++;
        ch[v[right]] = true;
        num++;
        if(num==k){
            temp = 0;
            for(int i=1; i<=d; i++) if(ch[i]) temp++;
            if(!ch[c]) temp++;
            if(ans<temp) ans = temp;
            temp = 0;
            for(int i=left+1; i<=right; i++){
                if(v[i]==v[left]) {temp++; break;}
            }
            if(temp==0) ch[v[left]] = false;
            left++;
            num--;
        }
    }
    cout << ans << "\n";
    return 0;
}
