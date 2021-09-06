#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int last=0, bus = 540; //09:00

void input(vector<string> &timetable){
    for(int i=0; i<timetable.size(); i++){
        string s = timetable[i];
        int hour = stoi(s.substr(0,2));
        int min = stoi(s.substr(3,2));
        int t = hour*60+min;
        v.push_back(t);
    }
}

void shuttle(int n, int m, int t){ // n : 셔틀운행 횟수,  m : 한 셔틀에 타는 최대 인원, t : 셔틀 운행 간격
    int cnt = 0;
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        int full = m;
        for(int j=cnt; j<v.size(); j++){
            if(v[j]<=bus){
                cnt++;
                full--;
                if(full==0) break;
            }
        }
        if(i+1==n){ // 마지막 버스
            if(full==0) last = v[cnt-1]-1;
            else last = bus;
        }
        bus += t;
        if(bus>=60*24) break;
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    input(timetable);
    shuttle(n,m,t);
    int hour = last/60;
    if(hour<10) answer += "0" + to_string(hour);
    else answer += to_string(hour);
    answer += ":";
    int min = last%60;
    if(min<10) answer += "0" + to_string(min);
    else answer += to_string(min);
    return answer;
}
