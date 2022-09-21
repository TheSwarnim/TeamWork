/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int distributeCoins(TreeNode root) {
        dfs(root);
        
        return res;
    }
    
    int res = 0;
    private int dfs(TreeNode root){
        if(root == null){
            return 0;
        }
        
        int balance = root.val;
        
        int left = dfs(root.left);
        int right = dfs(root.right);
        
        res += Math.abs(left) + Math.abs(right);
        balance += left + right;
        
        return balance-1;
    }
}