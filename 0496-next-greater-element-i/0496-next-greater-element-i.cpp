class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;
        map<int,int> mpp;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            mpp[nums2[i]] = ans[i];
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            res.push_back(mpp[nums1[i]]);
        }
        return res;
    }
};