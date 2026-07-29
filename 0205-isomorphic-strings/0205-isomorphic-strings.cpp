class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        map<char,char> hash1,hash2;
        for(int i = 0; i < n; i++) {
            if(!hash1[s[i]]) {
                hash1[s[i]] = t[i];
            }
            else if(hash1[s[i]] != t[i]) {
                return false;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!hash2[t[i]]) {
                hash2[t[i]] = s[i];
            }
            else if(hash2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};