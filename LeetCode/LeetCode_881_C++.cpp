// The problem link : https://leetcode.com/problems/boats-to-save-people/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left=0, right=people.size()-1, cnt=0; // cnt : 한 대의 보트를 2명이 타는 경우
        while(left<right){
            if(people[left]+people[right]<=limit){
                left++;
                right--;
                cnt++;
            }
            else right--;
        }
        return people.size()-cnt;
    }
};
