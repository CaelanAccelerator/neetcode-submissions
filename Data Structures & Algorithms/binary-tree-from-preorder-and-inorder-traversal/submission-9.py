# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        m = {}
        for i in range(len(inorder)):
            m[inorder[i]] = i 
        def dfs(pre_l, in_l, in_r):
            
            nonlocal preorder, inorder, m
            if in_l > in_r:
                return None
            res = TreeNode(preorder[pre_l],None,None)
            i = m[preorder[pre_l]] #for inorder
            res.left = dfs(pre_l + 1, in_l, i - 1)
            res.right = dfs(pre_l + i - in_l + 1, i + 1, in_r)
            return res
        return dfs(0,0,len(inorder)-1)
        