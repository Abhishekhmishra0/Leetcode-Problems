class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1e9, sum = nums[0], cnt = 1, maxi_cnt = 1;
        set<int> st(nums.begin(), nums.end());
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
                cnt++;
            }
            else {
                break;
            }
        }
        while(st.find(sum) != st.end()) {
            sum++;
        }
        return sum;
    }
};