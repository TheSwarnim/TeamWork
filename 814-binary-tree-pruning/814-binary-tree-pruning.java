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
    public TreeNode pruneTree(TreeNode root) {
        if(root == null){
            return null;
        }
        
        return dfs(root) ? root : null;
    }
    
    private boolean dfs(TreeNode root){
        if(root == null){
            return false;
        }
        
        var left = dfs(root.left);
        var right = dfs(root.right);
        
        if(!left){
            root.left = null;
        }
        if(!right){
            root.right = null;
        }
        
        return (left|right|(root.val == 1 ? true : false));
    }
}