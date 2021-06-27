// The problem : https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkPermutation(int s1[], int s2[]){
        for(int i=0; i<26; i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
  
    bool checkInclusion(string s1, string s2) {
        int sone[26], stwo[26];
        memset(sone,0,sizeof(sone));
        memset(stwo,0,sizeof(stwo));
        for(int i=0; i<s1.size(); i++) sone[s1[i]-'a']++;
        for(int i=0; i<s2.size(); i++){
            stwo[s2[i]-'a']++;
            if(i>=s1.size()) stwo[s2[i-s1.size()]-'a']--;
            if(i>=s1.size()-1&&checkPermutation(sone,stwo)) return true;
        }
        return false;
    }
};
