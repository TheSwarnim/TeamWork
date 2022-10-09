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
    bool findTarget(TreeNode* root, int k) {
        auto arr = preorder(root);
        int left = 0, right = arr.size() - 1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == k){
                return true;
            } else if(sum < k){
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
    
    vector<int> preorder(TreeNode* root){
        vector<int> res;
        
        stack<TreeNode*> st;
        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        
        return res;
    }
};