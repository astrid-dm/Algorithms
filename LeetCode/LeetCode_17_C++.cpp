class Solution {

    string phone[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> ans;

public:
    vector<string> letterCombinations(string digits) {
        string res = "";
        if (digits != "") dfs(digits, 0, res);
        return ans;
    }
    void dfs(string s1, int cnt, string s2) {
        if (s1.size() == cnt) {
            ans.push_back(s2);
            return;
        }
        for (int i = cnt; i < s1.size();i++) {
            for (int j = 0; j < phone[s1[i] - 48].size(); j++) {
                s2 += phone[s1[i] - 48][j];
                dfs(s1, cnt + 1, s2);
                s2.erase(s2.size() - 1, 1); // 글자를 지우려는 위치, 해당 위치부터 지우는 글자 갯수
            }
            break; // 중요
        }
    }
}; 
