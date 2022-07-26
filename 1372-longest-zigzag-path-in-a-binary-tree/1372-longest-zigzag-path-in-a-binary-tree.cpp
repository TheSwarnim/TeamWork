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
    int longestZigZag(TreeNode* root) {
        return max(
            dfs(root, true, -1),
            dfs(root, false, -1)
        );
    }
    
    int dfs(TreeNode *n, bool left, int depth){
        return n == nullptr ? depth :
            max(dfs(left ? n->left : n->right, !left, depth + 1), 
                dfs(left ? n->right : n->left, left, 0));
    }
};