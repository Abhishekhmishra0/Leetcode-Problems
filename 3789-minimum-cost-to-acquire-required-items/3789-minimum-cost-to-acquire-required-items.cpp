class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1e18;
        ans = min(ans, max(need1, need2) * 1LL * costBoth);
        ans = min(ans, need1 * 1LL * cost1 + need2 * 1LL * cost2);
        if(need1 >= need2) {
            ans = min(ans, (need1 - need2) * 1LL * cost1 + costBoth * 1LL * need2);
            ans = min(ans, need1 * 1LL * costBoth);
            
        }
        else {
            ans = min(ans, need2 * 1LL * costBoth);
            ans = min(ans, (need2 - need1) * 1LL * cost2 + need1 * 1LL * costBoth);
        }
        return ans;
    }
};