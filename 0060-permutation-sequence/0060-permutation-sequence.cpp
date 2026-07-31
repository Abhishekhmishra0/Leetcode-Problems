class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++) {
            s += to_string(i);
        }
        if(k == 1) {
            return s;
        }
        vector<int> fact(n + 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        int cnt = 0;
        k--;
        string ans = "";
        while(cnt < n) {
            int block = fact[n - cnt - 1];
            int idx = k / block;
            ans += s[idx];
            s.erase(idx, 1);
            k = k % block;
            cnt++;
        }
        return ans;
    }
};