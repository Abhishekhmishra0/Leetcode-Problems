class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < pre.size(); i++) {
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                st.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                    st.push(adjNode);
                }
            }
        }
        return st.size() == n;
    }
};