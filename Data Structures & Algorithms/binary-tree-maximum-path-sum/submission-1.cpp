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
    int max_sum = INT_MIN; 
public: 
    int dfs(TreeNode* root) { 
        if (!root) return 0; 
        auto left_sum = max(0, dfs(root->left)); 
        auto right_sum = max(0, dfs(root->right));   
        max_sum = max(max_sum, left_sum + right_sum + root->val); 
        return root->val + max(left_sum, right_sum); 
    }
    int maxPathSum(TreeNode* root) {
        dfs(root); 
        return max_sum; 
    }
};
