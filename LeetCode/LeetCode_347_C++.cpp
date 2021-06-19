// The problem link : https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        return (a.second>b.second);
    }    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),comp);
        for(int i=0; i<k; i++) ans.push_back(v[i].first);
        return ans;
    }
};
