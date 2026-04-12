class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(nums[i]) {
                int r = nums[i] % 10;
                nums[i] /= 10;
                ans += (r == digit);
            }
        }
        return ans;
    }
};