class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        auto isPossible = [&](int x) -> bool {
            int cnt = 1;
            int sum = nums[0];
            for(int i = 1; i < n; i++) {
                if(sum + nums[i] > x) {
                    cnt++;
                    sum = nums[i];
                }
                else {
                    sum += nums[i];
                }
            }
            return cnt <= k;
        };
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};