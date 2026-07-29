class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        int m = 1e9;
        for(int i = 0; i < n; i++) {
            m = min(m, (int)strs[i].size());
        }
        int i = 0;
        while(i < m) {
            bool check = true;
            char ch = strs[0][i];
            for(int j = 1; j < n; j++) {
                if(strs[j][i] != ch) {
                    check = false;
                    break;
                }
            }
            if(check) {
                ans += strs[0][i];
            }
            else {
                break;
            }
            i++;
        }
        return ans;
    }
};