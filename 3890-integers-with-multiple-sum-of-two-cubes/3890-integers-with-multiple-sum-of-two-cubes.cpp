class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> mpp;
        for(int i = 1; i <= 1000; i++) {
            for(int j = i + 1; j <= 1000; j++) {
                int res = i * i * i + j * j * j;
                if(res > n) continue;
                mpp[res]++;
            }
        }
        vector<int> ans;
        for(auto it : mpp) {
            if(it.second >= 2)
                ans.push_back(it.first);
        }
        return ans;
    }
};