class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int arr[1001] = {0,};
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<=i+nums[i]; j++){
                if(arr[j]!=0); // 가만 있어라
                else arr[j] = arr[i]+1;
                if(j==nums.size()-1) break;
            }
        }
        return arr[nums.size()-1];
    }
};
