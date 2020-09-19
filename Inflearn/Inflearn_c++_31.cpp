#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(string n){
    string c = "0", h= "0";
    int ans = 0;
    bool check = false;
    for(int i=1; i<n.length(); i++){
        if(n[i]>='0'&&n[i]<='9'&&check==false) {
            c+=n[i];
        }
        else if(n[i]=='H') check = true;
        else if(n[i]>='0'&&n[i]<='9'&&check==true){
            h+=n[i];
        }
    }
    if(c=="0") c="1";
    if(h=="0") h="1";
    ans = (stoi(c)*12) + stoi(h);
    cout << ans << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    double result;

    string N;

    cin >> N;
    
    start = clock();
    check(N);
    end = clock();
    
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", result);
    
    return 0;
}
