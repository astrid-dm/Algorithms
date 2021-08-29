// The problem link : https://programmers.co.kr/learn/courses/30/lessons/42885
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, left=0, right=people.size()-1;
    sort(people.begin(),people.end());
    while(left<=right){
        if(people[left]+people[right]<=limit){
            answer++;
            left++;
            right--;
        }
        else if(people[left]+people[right]>limit){
            answer++;
            right--;
        }
    }
    return answer;
}
