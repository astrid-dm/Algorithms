#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,a,b,c,x,y,z,maxi = 0, mini = 900001;
    cin >> n;
    cin >> a >> b >> c;
    int arr[3] = {a,b,c}, arr2[3] = {a,b,c};
    int samp[3] = {0,0,0}, samp2[3] = {0,0,0};
    for(int i=2; i<=n; i++){
        cin >> x >> y >> z;
        for(int i=0; i<3; i++){
            int temp = 0, temp2 = 0;
            if(i==0){
                temp = max(x+arr[0],x+arr[1]);
                temp2 = min(x+arr2[0],x+arr2[1]);
            }
            else if(i==1){
                temp = max(max(y+arr[0],y+arr[1]),y+arr[2]);
                temp2 = min(min(y+arr2[0],y+arr2[1]),y+arr2[2]);
            }
            else{
                temp = max(z+arr[1],z+arr[2]);
                temp2 = min(z+arr2[1],z+arr2[2]);
            }
            samp[i] = temp;
            samp2[i] = temp2;
        }
        for(int i=0; i<3; i++){
            arr[i] = samp[i];
            arr2[i] = samp2[i];
        }
    }
    for(int i=0; i<3; i++){
        if(arr[i]>maxi) maxi = arr[i];
        if(arr2[i]<mini) mini = arr2[i];
    }
    cout << maxi << " " << mini << "\n";
    return 0;
}
