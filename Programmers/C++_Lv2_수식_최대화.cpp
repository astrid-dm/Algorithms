#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long go(long long a, long long b, char c){
    if(c=='+') return a+b;
    else if(c=='*') return a*b;
    else return a-b;
}

long long solution(string expression) {
    long long answer = 0;
    string temp = "";
    vector<char> basic_operation = {'*','+','-'};
    vector<char> cal;
    vector<long long> num;
    for(auto i:expression){
        if(i=='*'||i=='-'||i=='+') {
            cal.push_back(i);
            num.push_back(stoll(temp)); // string to long long
            temp="";
        }
        else temp += i;
    }
    num.push_back(stoll(temp)); // 마지막 숫자
    do{
        vector<long long> temp_num = num;
        vector<char> temp_cal = cal;
        for(int i=0; i<3; i++){
            for(int j=0; j<temp_cal.size(); j++){
                if(basic_operation[i]==temp_cal[j]){
                    temp_num[j] = go(temp_num[j],temp_num[j+1],temp_cal[j]);
                    temp_num.erase(temp_num.begin()+j+1);// 숫자를 지운다
                    temp_cal.erase(temp_cal.begin()+j);// 계산식을 지운다
                    j--; // 주의! 1개 지웠으니 한 번 뒤로 되돌아가야한다
                }
            }
        }
        answer = max(abs(temp_num[0]),answer);
    }while(next_permutation(basic_operation.begin(), basic_operation.end()));
    return answer;
}
