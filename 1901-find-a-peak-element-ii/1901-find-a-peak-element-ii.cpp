class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int left = -1, right = -1;
            int maxi = 0;
            int maxi_idx = -1;
            for(int i = 0; i < n; i++) {
                if(mat[i][mid] > maxi) {
                    maxi = mat[i][mid];
                    maxi_idx = i;
                }
            }
            if(mid - 1 >= 0) {
                left = mat[maxi_idx][mid - 1];
            }
            if(mid + 1 < m) {
                right = mat[maxi_idx][mid + 1];
            }
            if(mat[maxi_idx][mid] > right && mat[maxi_idx][mid] > left) {
                return {maxi_idx, mid};
            }
            else if(mat[maxi_idx][mid] < right) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};