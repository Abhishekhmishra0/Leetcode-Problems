class Solution {
public:
    bool isDiff(int x, int y) {
        return ((x < 0 && y > 0) || (x > 0 && y < 0));
    }
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(!st.empty() && isDiff(st.top(), arr[i]) && st.top() > 0 && arr[i] < 0 && abs(st.top()) == abs(arr[i])) {
                st.pop();
                continue;
            }
            bool check = true;
            while(!st.empty() && st.top() > 0 && arr[i] < 0 && abs(st.top()) <= abs(arr[i])) {
                 if(abs(st.top()) == abs(arr[i])) {
                    st.pop();
                    check = false;
                    break;
                }
                st.pop();
            }
            if(!check) continue;
            if(!st.empty() && st.top() > 0 && arr[i] < 0 && abs(st.top()) > abs(arr[i])) {
                continue;
            }
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