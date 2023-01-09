// The problem link : https://leetcode.com/problems/jewels-and-stones/description/
// The result : 5ms, 41.8MB
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        String[] jTemp = jewels.split("");
        String[] sTemp = stones.split("");
        
        int ans = 0;
        for(int i=0; i<jewels.length(); i++) {
            for(int j=0; j<stones.length(); j++) {
                if(jTemp[i].equals(sTemp[j])) ans++;
            }
        }
        
        return ans;
    }
}
