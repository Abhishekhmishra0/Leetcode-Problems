class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        double ans = 0.0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(j < m) {
                ans = ans + double((prices[i] * (100 - discounts[j])) / 100.0);
                j++;
            }
            else {
                ans += prices[i];
            }
        }
        return ans;
    }
};