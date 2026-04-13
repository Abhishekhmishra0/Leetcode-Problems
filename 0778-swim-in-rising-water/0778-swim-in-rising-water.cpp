class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<array<int,3>> pq;
        pq.push({-grid[0][0], 0, 0});
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        dist[0][0] = grid[0][0];
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int val = -it[0];
            int row = it[1];
            int col = it[2];
            if(dist[row][col] < val) {
                continue;
            }
            for(int i = 0; i < 4; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0) {
                    if(dist[nrow][ncol] > max(grid[nrow][ncol], val)) {
                        dist[nrow][ncol] = max(grid[nrow][ncol], val);
                        pq.push({-dist[nrow][ncol], nrow, ncol});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};