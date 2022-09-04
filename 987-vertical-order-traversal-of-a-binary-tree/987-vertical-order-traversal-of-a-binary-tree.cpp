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
    typedef vector<pair<int, int>> vi;
    typedef vector<vi> vvi;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vvi mat(2002);
        
        dfs(root, mat, 1000, 0);
        
        vector<vector<int>> res;
        for(auto a : mat){
            if(!a.empty()){
                sort(begin(a), end(a));
                vector<int> ar;
                for(auto p : a){
                    ar.push_back(p.second);
                }
                res.push_back(ar);
            }
        }
        return res;
    }
    
    void dfs(TreeNode *root, vvi &mat, int row, int col){
        mat[row].push_back({col, root->val});
        
        if(root->left != nullptr){
            dfs(root->left, mat, row-1, col+1);
        }
        if(root->right != nullptr){
            dfs(root->right, mat, row+1, col+1);
        }
    }
};