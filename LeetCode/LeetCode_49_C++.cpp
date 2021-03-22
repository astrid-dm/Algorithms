class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        vector<vector<string>> ans;
        bool ch[10001] = {false,};
        string s1 = "", s2 = "", cnt = "";

        for (int i = 0; i < strs.size(); i++) {
            cnt = strs[i];
            sort(cnt.begin(), cnt.end());
            temp.push_back(cnt);
        }
        for (int i = 0; i < strs.size(); i++) {
            if (!ch[i]) {
                ch[i] = true;
                ans.push_back({ strs[i] }); // 오 중괄호 넣으니까 되네?
                s1 = temp[i];
                for (int j = i + 1; j < strs.size(); j++) {
                    if (!ch[j]) {
                        s2 = temp[j];
                        if (s1 == s2) {
                            ans[ans.size() - 1].push_back(strs[j]);
                            ch[j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
 
