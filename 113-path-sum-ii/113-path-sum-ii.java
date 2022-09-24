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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        
        if(root == null){
            return res;
        }
        
        dfs(root, targetSum, res, path, 0);
        
        return res;
    }
    
    void dfs(TreeNode root, int target, List<List<Integer>> res, List<Integer> path, int sum){
        sum += root.val;
        path.add(root.val);
        
        if(root.left == null && root.right == null){
            if(sum == target){
                res.add(new ArrayList<>(path));
            }
        } else {
            if(root.left != null){
                dfs(root.left, target, res, path, sum);
            }
            if(root.right != null){
                dfs(root.right, target, res, path, sum);
            }   
        }
        
        path.remove(path.size() - 1);
        sum -= root.val;
    }
}