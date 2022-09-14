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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10);
        int res = 0;
        dfs(root, path, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int> &path, int &res){
        path[root->val]++;
        
        if(root->left == nullptr and root->right == nullptr){
            if(checkPalin(path)){
                res++;
            }
            path[root->val]--;
            return;
        }
        
        if(root->left)
            dfs(root->left, path, res);
        if(root->right)
            dfs(root->right, path, res);
        
        path[root->val]--;
    }
    
    bool checkPalin(vector<int> &arr){
        int odd = 0;
        for(auto &x : arr){
            if(x%2){
                odd++;
            }
        }
        return odd <= 1;
    }
};