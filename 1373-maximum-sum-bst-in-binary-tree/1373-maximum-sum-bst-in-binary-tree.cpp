/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    vector<int> solve(TreeNode* root) {
        if(root == NULL) {
            ans = max(ans, 0);
            return {1, 0, -1000000000, 1000000000};
        }
        if (root -> left == NULL && root -> right == NULL) {
            ans = max(ans, root -> val);
            return {1, root -> val, root -> val, root -> val};
        }
        auto left = solve(root -> left);
        auto right = solve(root -> right);
        if(left[0] && right[0] && root -> val > left[2] && root -> val < right[3]) {
            ans = max(ans, root -> val + left[1] + right[1]);
            return {1, root -> val + left[1] + right[1], max({left[2],left[3],right[2],right[3], root -> val}), min({left[2],left[3],right[2],right[3], root -> val})};
        }
        return {0, -100000000, 100000000, -1000000000};
    }

    int maxSumBST(TreeNode* root) { 
        if(root == NULL) {
            return 0;
        }
        ans = INT_MIN; 
        auto it = solve(root);
        if(ans < 0) return 0;
        return ans;
    }
};