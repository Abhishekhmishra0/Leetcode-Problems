class Solution {
public:
    const int Mod = 1e9 + 7;
    long long mod_mul(long long a, long long b){
        return ((a % Mod) * (b % Mod)) % Mod;
    }
    long long mod_sub(long long a, long long b){
        return ((a % Mod - b % Mod) + Mod) % Mod;
    }
    int mod_add(int a, int b){return (a % Mod + b % Mod) % Mod;}
    long long binExp(long long a, long long b){
        if (b == 0) return 1;
        long long ans = binExp(a, b / 2);
        if (b & 1) return (a * ((ans * 1LL * ans) % Mod)) % Mod;
        else  return (ans * ans) % Mod;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        long long ans = 0;
        int cnt = 0;
        vector<pair<int,int>> v;
        long long zeros = 0;
        for(int i = 0; i < n; i++) {
            if(nums0[i] == 0) {
                zeros += nums1[i];
                continue;
            }
            v.push_back({nums1[i], nums0[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for(int i = 0; i < v.size(); i++) {
            cnt += v[i].second;
            int num = v[i].first;
            ans = mod_add(ans, mod_mul(binExp(2, cnt),mod_sub(binExp(2, num), 1)));
            cnt+=num;
        }
         while(zeros--) {
            ans = mod_add(ans, binExp(2LL, (long long)cnt));
            cnt++;
        }
        return ans;
    }
};