class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int maximum) {
        int ans = 0, mini = n + 1;    
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges) {
            if(it[2] <= maximum) {
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }
        } 
        for(int i = 0; i < n; i++) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, i});
            vector<int> dist(n, 1e9);
            dist[i] = 0;
            while(!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                int node = it.second;
                int wt = it.first;
                if(dist[node] != wt) {
                    continue;
                }
                for(auto adjNode : adj[node]) {
                    if(adjNode.second + wt < dist[adjNode.first] && adjNode.second + wt <= maximum) {
                        dist[adjNode.first] = wt + adjNode.second;
                        pq.push({dist[adjNode.first], adjNode.first});
                    }
                }
            }
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(dist[j] != 1e9 && j != i) {
                    cnt++;
                }
            }
            if(cnt <= mini) {
                ans = i;
                mini = cnt;
            }
        }

        return ans;
    }
};