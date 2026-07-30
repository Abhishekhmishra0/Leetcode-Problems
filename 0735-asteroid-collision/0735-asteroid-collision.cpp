class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            bool check = false;
            while(!st.empty() && st.top() > 0 && arr[i] < 0) {
                if(abs(st.top()) > abs(arr[i])) {
                    check = true;
                    break;
                }
                else if(abs(st.top()) == abs(arr[i])) {
                    check = true;
                    st.pop();
                    break;
                }
                else {
                    st.pop();
                }
            }
            if(check) continue;
            st.push(arr[i]);
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};