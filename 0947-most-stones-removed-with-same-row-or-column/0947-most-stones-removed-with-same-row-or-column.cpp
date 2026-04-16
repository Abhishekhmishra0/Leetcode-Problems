class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n,0);
        function<void(int)> dfs = [&](int node){
            vis[node] = 1;
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    dfs(adjNode);
                }
            }
        };
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return n - ans;
    }
};