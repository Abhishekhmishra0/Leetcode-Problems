class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n, 0);
        auto dfs = [&](int node, auto&& F) -> void {
            vis[node] = 1;
            for(auto adjNode : adj[node]) {
                if(!vis[adjNode]) {
                    F(adjNode, F);
                }
            }
        };
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, dfs);
            }
        }
        return ans;
    }
};