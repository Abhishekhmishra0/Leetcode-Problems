class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<array<int,3>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool check = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j] == 1) {
                    check = false;
                }
            }
        }
        if(check) return 0;
        if(q.empty()) return -1;
        cout << q.size();
        int ans = 0;
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node[0];
            int col = node[1];
            int time = node[2];
            ans = max(ans, time);
            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = dcol[i] + col;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol, time + 1});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};