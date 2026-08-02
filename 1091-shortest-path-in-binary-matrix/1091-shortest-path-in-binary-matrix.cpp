class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        int drow[] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int wt = q.front()[2];
            q.pop();
            for(int i = 0; i < 8; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !grid[nrow][ncol]) {
                    if(dist[row][col] + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = 1 + dist[row][col];
                        q.push({nrow, ncol, dist[nrow][ncol]});
                    }
                }
            }
        }
        if(dist[n - 1][m - 1] == 1e9) return -1;
        return dist[n - 1][m - 1];
    }
};