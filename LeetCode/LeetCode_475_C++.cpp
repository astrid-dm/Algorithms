// The problem link : https://leetcode.com/problems/heaters/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        vector<int> dis(houses.size(),INT_MAX);
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        for(int i=0,j=0; i<houses.size(); i++){ // Right
            if(j>=heaters.size()) break;
            if(houses[i]<=heaters[j]){
                dis[i]=heaters[j]-houses[i];
            }   
            else i--,j++;
        }
        for(int i=houses.size()-1, j=heaters.size()-1; i>=0; i--){ // Left
            if(j<0) break;
            if(houses[i]>=heaters[j]){
                dis[i] = min(dis[i],houses[i]-heaters[j]);
            }
            else i++,j--;
        }
        for(int i=0; i<dis.size(); i++) if(dis[i]>ans) ans = dis[i];
        return ans;
    }
};
