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
    int count=0; 
public: 
    void dfs(TreeNode* root, int max_seen) { 
        if (!root) return; 
        if (root->val >= max_seen) count++; 
        dfs(root->left, max(max_seen, root->val)); 
        dfs(root->right, max(max_seen, root->val)); 
    }
    int goodNodes(TreeNode* root) {
        // dfs and keep track of maximum seen so far 
        dfs(root, -101);  
        return count; 
    }
};
