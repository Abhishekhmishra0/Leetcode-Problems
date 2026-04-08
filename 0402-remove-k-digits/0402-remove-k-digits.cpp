class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) return "0";
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while(!ans.empty() && ans.back() == '0') {
            ans.erase(ans.size() - 1, 1);
        }
        reverse(ans.begin(), ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};