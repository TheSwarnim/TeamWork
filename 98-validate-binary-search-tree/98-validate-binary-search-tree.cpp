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
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root) {        
        if(root->left != nullptr && !isValidBST(root->left)){
            return false;    
        }
        
        if(root->val <= prev){
            return false;
        }
        prev = root->val;
        if(root->right != nullptr && !isValidBST(root->right)){
            return false;
        }
        
        return true;
    }
};