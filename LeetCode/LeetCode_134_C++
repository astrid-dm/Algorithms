class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int indexsum = 0, totalsum = 0, index = 0;
        for(int i=0; i<gas.size(); i++){
            indexsum += gas[i] - cost[i];
            totalsum += gas[i] - cost[i];
            if(indexsum<0){
                index = i+1;
                indexsum = 0;
            }
        }
        return totalsum < 0 ? -1 : index;
    }
};
