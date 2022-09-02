# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        res = []
        q = [root]
        
        while len(q) > 0:
            size = len(q)
            ttl = 0
            for i in range(size):
                node = q[0]
                q.pop(0)
                ttl += node.val
                
                if node.left != None:
                    q.append(node.left)
                
                if node.right != None:
                    q.append(node.right)
            res.append(ttl/size)
        
        return res