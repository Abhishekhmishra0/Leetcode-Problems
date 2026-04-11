class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes(110001);
        vector<bool> isPrime(110001,1);
        set<int> st;
        isPrime[1] = 0;
        for(int i = 2; i < 110001; i++) {
            if(isPrime[i]) {
                st.insert(i);
                for(int j = 2 * i; j < 110001; j+=i) {
                    isPrime[j] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(st.find(nums[i]) == st.end()) {
                    auto it = st.lower_bound(nums[i]);
                    ans += *it - nums[i];
                }
            }
            else {
                while(st.find(nums[i]) != st.end()) {
                    nums[i]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};