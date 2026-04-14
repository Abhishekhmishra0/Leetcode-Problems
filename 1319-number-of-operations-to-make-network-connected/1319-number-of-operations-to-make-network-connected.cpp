class DisjointSet {
    public:
    vector<int> size, par;
    DisjointSet(int n) {
        size.resize(n + 5, 1);
        par.resize(n + 5);
        for(int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    int findUpar(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = findUpar(par[x]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_u] <= size[ulp_v]) {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        int m = conn.size();
        DisjointSet d(n);
        int extra = 0;
        for(int i = 0; i < m; i++) {
            int u = conn[i][0];
            int v = conn[i][1];
            if(d.findUpar(u) == d.findUpar(v)) {
                extra++;
            }
            else {
                d.unionBySize(u, v);
            }
        }
        int components = 0;
        set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(d.findUpar(i));
        }
        components = st.size();
        if(extra < components - 1) {
            return -1;
        }
        return components - 1;
    }
};