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
    /**
     * to do this question, we need to iterate to every path in tree from the root
     * to the leaf.
     * We will also need to increment the sum and add all nodes in between the path
     * from the root to the leaf.
     * Lastly we check if the sum is equal to the target.
    */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path; // to store the path from the root to the leaf
        findPathSum(root, targetSum, 0, path, ans);
        return ans;
    }
    
    void findPathSum(TreeNode* root, int targetSum, int cursum, vector<int> &path, vector<vector<int>> &ans){
        if(!root) return; // if the root is null, we return
        
        cursum += root->val; // increment the current sum
        path.push_back(root->val); // add the current node to the path
        
        if(root->left == nullptr && root->right == nullptr){ // check if the current node is a leaf
            if(cursum == targetSum) 
                ans.push_back( vector<int>(begin(path), end(path)) ); // if the current sum is equal to the target sum, we add the path to the answer
        }
        
        // recursively call the function to find the path from the left and right child
        findPathSum(root->left, targetSum, cursum, path, ans);         
        findPathSum(root->right, targetSum, cursum, path, ans);

        // backtrack from current node by removing the current node from the path
        // and it's sum from the current sum        
        cursum -= root->val;
        path.pop_back();
    }
};