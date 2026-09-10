/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
public:
    pair<int,int> solve(TreeNode* root) {
        if(root == NULL) return {0, 0};
        auto l = solve(root -> left);
        auto r = solve(root -> right);
        int sum = l.first + r.first + root -> val;
        int avg = sum / (l.second + r.second + 1);
        if(avg == root -> val) {
            ans++;
        }
        return {sum, l.second + r.second + 1};

    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return ans;
    }
};