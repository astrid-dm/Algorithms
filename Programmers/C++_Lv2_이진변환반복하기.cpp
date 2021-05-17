#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int a = 0, b = 0;
    while(s!="1"){
        int cnt = 0, temp = 0;
        string temp2 = "";
        for(int i=0; i<s.size(); i++) if(s[i]=='1') cnt++;
        b+=s.size()-cnt;
        while(cnt!=1){
            temp = cnt%2;
            temp2+=(temp+'0');
            cnt/=2;
        }
        temp2+='1';
        reverse(temp2.begin(),temp2.end());
        s=temp2;
        a++;
    }
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}
