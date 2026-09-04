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
    vector<unordered_map<TreeNode*, int>> vec; 
   public:
    int dfs(TreeNode* root, bool can_rob) {
        if (!root) return 0; 
        if (vec[can_rob].count(root)) return vec[can_rob][root]; 
        int rob_here = 0, skip_here = 0;
        // rob this node
        if (can_rob) {
            rob_here = root->val + dfs(root->left, false) +
                           dfs(root->right, false);
        }
        skip_here = dfs(root->left, true) + dfs(root->right, true);
        return vec[can_rob][root] = max(rob_here, skip_here);
    }
    int rob(TreeNode* root) { 
        vec.resize(2); 
        return dfs(root, true); 
    }
};