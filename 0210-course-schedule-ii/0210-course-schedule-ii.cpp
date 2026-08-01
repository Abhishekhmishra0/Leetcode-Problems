class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < pre.size(); i++) {
            int u = pre[i][0];
            int v = pre[i][1];
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0), ans;
        auto dfs = [&](int node,auto&& F) -> bool {
            vis[node] = 1;
            for(auto adjNode : adj[node]) {
                if(vis[adjNode] == 1) {
                    return true;
                }
                else if(vis[adjNode] == 0) {
                    bool check = F(adjNode, F);
                    if(check) return true;
                }
            }
            vis[node] = 2;
            ans.push_back(node);
            return false;
        };
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bool check = dfs(i, dfs);
                if(check) return {};
            }
        }
        if(ans.size() < n) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};