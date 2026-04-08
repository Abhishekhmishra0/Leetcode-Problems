class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> pse(n), nse(n), pge(n), nge(n);
        stack<long long> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                pse[i] = st.top();
            }
            else {
                pse[i] = -1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                pge[i] = st.top();
            }
            else {
                pge[i] = -1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nse[i] = st.top();
            }
            else {
                nse[i] = n;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nge[i] = st.top();
            }
            else {
                nge[i] = n;
            }
            st.push(i);
        }
        long long mini = 0;
        long long maxi = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            mini += left * right * nums[i];
        }
         for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            maxi += left * right * nums[i];
        }
        cout << maxi << " " << mini << endl;
        return maxi - mini;
    }
};