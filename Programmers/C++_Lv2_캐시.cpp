#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    for(int i=0; i<cities.size(); i++){
        string city = cities[i];
        bool ch = false;
        for(int j=0; j<city.size(); j++) city[j] = tolower(city[j]);
        for(int j=0; j<dq.size(); j++){
            if(dq[j]==city){
                dq.erase(dq.begin()+j);
                ch = true;
                break;
            }
        }
        if(ch) answer++;
        else{
            if(!dq.empty()&&dq.size()>=cacheSize) dq.pop_front();
            answer += 5;
        }
        if(cacheSize!=0) dq.push_back(city); // 주의
    }
    return answer;
}
