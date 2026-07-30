class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map<char,int> vis;
            set<pair<int,char>> st;
            for(int j = i; j < n; j++) {
                if(!vis[s[j]]) {
                    st.insert({1, s[j]});
                    vis[s[j]]++;
                }
                else {
                    st.erase(st.find({vis[s[j]], s[j]}));
                    vis[s[j]]++;
                    st.insert({vis[s[j]], s[j]});
                }
                if(st.size() <= 1) continue;
                auto it = prev(st.end());
                int res = (*it).first - (*(st.begin())).first;
                ans += res;
            }
        }
        return ans;
    }
};