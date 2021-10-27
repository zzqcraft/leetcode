# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self, root: Optional[TreeNode], val: int) -> (int, Optional[TreeNode]):
        if root is None:
            return (-1, None)
        elif root.val == val:
            return (1, None)
        else:
            left, p = self.depth(root.left, val)
            if left > 0:
                if left == 1:
                    return (left + 1, root)
                else:
                    return (left + 1, p)
            right, p = self.depth(root.right, val)
            if right > 0:
                if right == 1:
                    return (right + 1, root)
                else:
                    return (right + 1, p)
            return (-1, None)
        
        
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        dx,px = self.depth(root, x)
        dy,py = self.depth(root, y)
        
        if dx == dy and px != py:
            return True
        else: 
            return False
