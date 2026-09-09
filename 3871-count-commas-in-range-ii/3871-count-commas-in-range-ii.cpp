class Solution {
public:
    long long countCommas(long long n) {
        long long base = 1000;
        long long maxi = 9999;
        long long ans = 0;
        string s = to_string(n);
        if(s.size() <= 3) return 0;
        int i = 3;
        while(i < s.size() - 1) {
            ans += (maxi - base + 1) * (i / 3);
            base *= 10;
            maxi *= 10;
            maxi += 9;
            i++;
        }
        ans += (n - base + 1) * (i / 3);
        return ans;
    }
};