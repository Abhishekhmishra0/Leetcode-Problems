class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        set<int> row, col;
        int n = nums.size();
        int m = nums[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(row.find(i) != row.end() || col.find(j) != col.end()) {
                    nums[i][j] = 0;
                }
            }
        }
    }
};