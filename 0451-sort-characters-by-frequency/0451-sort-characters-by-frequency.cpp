class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char,int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }
        set<pair<int,char>> st;
        string ans = "";
        for(auto it : mpp) {
            st.insert({-it.second, it.first});
        }
        for(auto it : st) {
            int num = mpp[it.second];
            while(num) {
                ans += it.second;
                num--;
            }
        }
        return ans;
    }
};