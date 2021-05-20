#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 2, pos ,left = a[0], right = a[a.size()-1];
    vector<bool> ch(a.size());
    for(int i=1; i<a.size()-1; i++){
        pos = a[i];
        if(left>a[i]){
            ch[i] = true;
            left = a[i];
        }
    }
    for(int i=a.size()-1; i>=1; i--){
        pos = a[i];
        if(right>a[i]){
            ch[i] = true;
            right = a[i];
        }
    }
    for(int i=1; i<a.size()-1; i++) if(ch[i]) answer++;
    return answer;
}
