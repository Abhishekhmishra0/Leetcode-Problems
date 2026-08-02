class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it[2];
            int stops = it[0];
            int wt = it[1];
            if(stops > k) continue;
            for(auto adjNode : adj[node]) {
                if(wt + adjNode.second < dist[adjNode.first]) {
                    dist[adjNode.first] = wt + adjNode.second;
                    pq.push({stops + 1, dist[adjNode.first], adjNode.first});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};