// The problem : https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, now = 0, pos = 0, next=0;
        for(int i=0; i<height.size(); i++){
            if(height[i]==0) continue;
            stack<int> s;
            s.push(height[i]);
            now = height[i];
            for(int j=i+1; j<height.size(); j++){
                s.push(height[j]);
                next = j;
                if(height[j]>=now) break;
            }
            while(!s.empty()){
                pos = s.top();
                s.pop();
                if(pos>now) now = pos;
                if(now-pos>0) ans+=now-pos;
            }
            if(next!=height.size()-1) i=next-1;
            else break;
        }
        return ans;
    }
};
