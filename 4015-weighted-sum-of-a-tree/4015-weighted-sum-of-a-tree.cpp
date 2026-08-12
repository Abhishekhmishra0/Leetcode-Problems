class Solution {
public:
    long long weightedSum(vector<int>& par, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }
        int h = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            h++;
            int l = q.size();
            for(int i = 0; i < l; i++) {
                int node = q.front();
                q.pop();
                for(auto adjNode : adj[node]) {
                    if(adjNode != par[node]) {
                        q.push(adjNode);
                    }
                }
            }
        }
        vector<int> depth(n, 1);
        auto dfs = [&](int node, int p, auto&& F) -> void {
            for(auto adjNode : adj[node]) {
                if(adjNode != p) {
                    depth[adjNode] = depth[node] + 1;
                    F(adjNode, node, F);
                }
            }
        };
        dfs(0, -1, dfs);
        for(int i = 0; i < n; i++) {
            cout << depth[i] << " ";
        }
        long long ans = 0;
        auto DFS = [&](int node, int p, auto&& F) -> void {
            ans = ans + nums[node] * 1LL * (h - depth[node] + 1);
            for(auto adjNode : adj[node]) {
                if(adjNode != p) {
                    F(adjNode, node, F);
                }
            }
        };
        DFS(0, -1, DFS);
        return ans;
    }
};