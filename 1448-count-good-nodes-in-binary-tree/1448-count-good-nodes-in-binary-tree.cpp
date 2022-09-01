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
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, res, -1e5);
        return res;
    }
    
    void dfs(TreeNode *node, int &res, int prevMax){
        if(!node) return;
        
        if(node->val >= prevMax) res++;
        prevMax = max(node->val, prevMax);
        dfs(node->left, res, prevMax);
        dfs(node->right, res, prevMax);
    }
};