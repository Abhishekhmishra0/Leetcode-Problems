class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l = 0;
        int ans = 0;
        map<int,int> mpp;
        set<int> st;
        while(r < n) {
            mpp[nums[r]]++;
            if(mpp[nums[r]] > k) {
                st.insert(nums[r]);
            }
            while(l < r && !st.empty()) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] <= k) {
                    if(st.find(nums[l]) != st.end()) {
                        st.erase(st.find(nums[l]));
                    }
                }
                l++;
            }
            if(st.empty()) {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};