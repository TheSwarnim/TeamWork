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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        rightView(root, 0);
        return ans;
    }
    
    void rightView(TreeNode* root, int depth) {
        if(!root) return;
        if(ans.size() == depth){
            ans.push_back(root->val);
        }
        
        rightView(root->right, depth+1);
        rightView(root->left, depth+1);
    }
};