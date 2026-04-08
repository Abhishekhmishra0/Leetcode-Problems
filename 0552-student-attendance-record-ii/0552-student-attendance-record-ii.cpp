class Solution {
public:
    const int Mod = 1e9 + 7;
    int checkRecord(int n) {
        long long dp[n][3][4];
        memset(dp, -1, sizeof(dp));
        auto f = [&](int i, int a, int l, auto&& F) -> long long {
            if(i == n) {
                return 1;
            }
            if(dp[i][a][l] != -1) {
                return dp[i][a][l];
            }
            long long present = 0, absent = 0, late = 0;
            present = F(i + 1, a, 0, F);
            if(a < 1) {
                absent = F(i + 1, a + 1, 0, F);
            }
            if(l < 2) {
                late = F(i + 1, a, l + 1, F);
            }
            return dp[i][a][l] = (present % Mod + absent % Mod + late % Mod) % Mod;
        };
        return f(0,0,0,f) % Mod;
    }
};