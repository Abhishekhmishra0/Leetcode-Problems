class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
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
    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
    vector<int> f(int n) {
        vector<int> ans;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ans.push_back(i);
                if(i * i != n) {
                    ans.push_back(n / i);
                }
            }
        }
        return ans;
    }
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        DisjointSet d(maxi);
        map<int,int> mpp;
        for(int i = 0; i < n; i++) {
            vector<int> fact = f(nums[i]);
            for(auto x : fact) {
                if(x == 1 || x == nums[i]) continue;
                if(d.findUpar(x) != d.findUpar(nums[i])) {
                    d.unionBySize(x, nums[i]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            mpp[nums[i]] = d.findUpar(nums[i]);
        }
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(int i = 0; i < n; i++) {
            if(mpp[nums[i]] != mpp[temp[i]]) {
                return false;
            }
        }
        return true;
    }
};