class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        string temp = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                if(!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            }
            else {
                temp += s[i];
            }
        }
        if(!temp.empty()) {
            words.push_back(temp);
        }
        string ans = "";
        for(int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if(i != 0) ans += " ";
        }
        return ans;
    }
};