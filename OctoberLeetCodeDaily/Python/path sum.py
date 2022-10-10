
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        
        if root is None:
            return False
        
        def dfs(node, curr_sum):
            curr_sum += node.val
            if not node.left and not node.right:
                return targetSum == curr_sum
            
            return (node.left and dfs(node.left, curr_sum)) or (node.right and dfs(node.right, curr_sum))
        
        return dfs(root, 0)
