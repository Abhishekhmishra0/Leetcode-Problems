class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = -1, end = -1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = i - 1;
            int k = i + 1;
            int cnt = 1;
            while(j >= 0 && k < n) {
                if(s[j] == s[k]) {
                    cnt += 2;
                    j--;
                    k++;
                }
                else {
                    break;
                }
            }
            if(cnt > ans) {
                start = j + 1;
                end = k - 1;
                ans = cnt;
            }
            cnt = 1;
            if(i - 1 >= 0 && s[i - 1] == s[i]) {
                cnt = 2;
            }
            if(cnt == 1) continue;
            j = i - 2;
            k = i + 1;
            while(j >= 0 && k < n) {
                if(s[j] == s[k]) {
                    cnt += 2;
                    j--;
                    k++;
                }
                else {
                    break;
                }
            }
            if(cnt > ans) {
                start = j + 1;
                end = k - 1;
                ans = cnt;
            }
        }
        string res = "";
        for(int i = start; i <= end; i++) {
            res += s[i];
        }
        return res;
    }
};