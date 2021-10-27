# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if root is None:
            return None
        
        if root.left is not None:
            if self.removeLeafNodes(root.left, target) is None:
                root.left = None
        
        if root.right is not None:
            if self.removeLeafNodes(root.right, target) is None:
                root.right = None
        
        if root.left is None and root.right is None:
            if root.val == target:
                return None
            else:
                return root
        return root
