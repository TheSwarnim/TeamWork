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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return findBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* findBST(vector<int> &nums, int i, int j){
        if(i > j) return nullptr;
        
        int mid = i + (j - i)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = findBST(nums, i, mid-1);
        node->right = findBST(nums, mid+1, j);
        
        return node;
    }
};