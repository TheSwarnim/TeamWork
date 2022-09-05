"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        q, res = [root], []
        while q:
            res.append([node.val for node in q])
            q = [child for node in q for child in node.children if child]
        return res