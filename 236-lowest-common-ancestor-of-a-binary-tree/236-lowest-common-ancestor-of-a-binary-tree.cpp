/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef vector<TreeNode*> vi;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vi parr = dfs(root, p);
        vi qarr = dfs(root, q);
        
        int i = parr.size() - 1, j = qarr.size() - 1;
        while(i >= 0 && j >= 0 && parr[i]->val == qarr[j]->val){
            i--;
            j--;
        }
        
        return parr[i+1];
    }
    
    vi dfs(TreeNode* root, TreeNode* target){
        if(!root) return {};
        
        vi res;
        
        res = dfs(root->left, target);
        if(!res.empty()){
            res.push_back(root);
            return res;
        }
        res = dfs(root->right, target);
        if(!res.empty()){
            res.push_back(root);
            return res;
        }
        
        if(root == target){
            vi res;
            res.push_back(target);
            return res;
        }
        
        return {};
    }
};