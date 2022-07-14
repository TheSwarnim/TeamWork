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
    /*
    logic: all nodes in inorder that comes to the root node in preorder should be shilfted to left part of that tree, all other should shift to right of tree
    */
    typedef vector<int> vi;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        return buildTreeUtil(preorder, inorder, 0, n-1, 0);
    }
    
    TreeNode* buildTreeUtil(vi &preorder, vi &inorder, int inStart, int inEnd, int preIdx){
        if(preIdx >= preorder.size() || inStart > inEnd) 
            return nullptr;
        TreeNode *node = new TreeNode(preorder[preIdx]);
        int inIndex = 0; // index of the current node in inorder vector
        
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == (node->val)){
                inIndex = i;
                break;
            }
        }
        
        node->left = buildTreeUtil(preorder, inorder, inStart, inIndex - 1, preIdx+1);
        node->right = buildTreeUtil(preorder, inorder, inIndex+1, inEnd, preIdx + inIndex - inStart + 1);
        return node;
    }
};