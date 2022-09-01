# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = [0]
        
        def dfs(root, prevMaxVal):
            if root==None:
                return
            
            if root.val >= prevMaxVal:
                prevMaxVal = max(root.val, prevMaxVal)
                res[0] += 1
            
            dfs(root.left, prevMaxVal)
            dfs(root.right, prevMaxVal)
        
        dfs(root, int(-1e5))
        return res[0]