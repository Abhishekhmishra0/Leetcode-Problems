class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 1,cnt = 1;
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int i = 1, req = nums[0] + 1;
        while(i < n) {
            while(i < n && nums[i] == nums[i - 1]) i++;
            if( i >= n) break;
            if(nums[i] == req) {
                i++;
                cnt++;
                req++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
                req = nums[i] + 1;
                i++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};