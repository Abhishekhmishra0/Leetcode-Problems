class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 2);
        set<int> st;
        for(auto it : stones) {
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) != ds.findUpar(v + maxRow + 1)) {
                ds.unionBySize(u, v + maxRow + 1);
                st.insert(u);
                st.insert(v + maxRow + 1);
            }
        }
        int cnt = 0;
        for(auto it : st) {
            if(ds.findUpar(it) == it) {
                cnt++;
            }
        }
        return (int)stones.size() - cnt;
    }
};