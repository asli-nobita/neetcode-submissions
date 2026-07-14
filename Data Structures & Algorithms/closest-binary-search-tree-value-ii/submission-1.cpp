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

struct Comparator {  
    double k; 
    Comparator(double target) : k(target) {}
    bool operator()(int a, int b) { 
        return abs(a-k) < abs(b-k); 
    }
};  

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& values) { 
        if (!root) return; 
        inorder(root->left, values); 
        values.push_back(root->val); 
        inorder(root->right, values); 
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> values; 
        inorder(root, values); 
        Comparator comp(target); 
        priority_queue<int, vector<int>, Comparator> pq(comp); 
        for(int x:values) { 
            if(pq.size() < k) pq.push(x); 
            else if(abs(x-target) < abs(pq.top()-target)) {
                pq.pop(); 
                pq.push(x); 
            }
        } 
        vector<int> ans; 
        while(!pq.empty()) { 
            ans.push_back(pq.top()); 
            pq.pop(); 
        }
        return ans; 
    }
};
