class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int low = 0;
        int high = 1e9;
        int ans = -1;
        auto isPossible = [&](int x) -> bool {
            int cnt = 0;
            int res = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] <= x) {
                    cnt++;
                    if(cnt == k) {
                        res++;
                        cnt = 0;
                    }
                }
                else {
                    cnt = 0;
                }
            }
            return res >= m;

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