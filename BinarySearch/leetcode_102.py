# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        ans = []
        queue = [root]        
        while len(queue) != 0:
            next_queue, l = [], []
            for node in queue:
                l.append(node.val)
                if node.left != None:
                    next_queue.append(node.left)
                if node.right != None:
                    next_queue.append(node.right)
            queue.clear()
            queue.extend(next_queue)
            ans.append(l)
            
        return ans