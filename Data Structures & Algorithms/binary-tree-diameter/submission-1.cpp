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
    int diameter = 0; 
public:
    int dfs(TreeNode* root) { 
        if (!root) return 0; 
        auto left_ht = dfs(root->left); 
        auto right_ht = dfs(root->right); 
        diameter = max(diameter, left_ht + right_ht); 
        return 1 + max(left_ht, right_ht); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root); 
        return diameter; 
    }
};
