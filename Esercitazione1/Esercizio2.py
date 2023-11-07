class TreeNode:
    def __init__(self, val=0, left=None, right=None, flag = False):
        self.val = val
        self.left = left
        self.right = right
        self.flag = flag

class Solution: 
    def getLastSpot(self, head, numBalls, depth):
        if depth == 1:
            return head.val
        for i in range (0, numBalls):
            lastSpot = self.Recursive(head, depth)
        return lastSpot
    
    def Recursive(self, head, depth):
        if depth == 1:
            return head.val
        if head.flag == False:
            lastSpot = self.Recursive(head.left, depth-1)
        elif head.flag == True:
            lastSpot = self.Recursive(head.right, depth-1)
        return lastSpot
    
    def buildTree(self, node_val, height):
        if height <= 0:
            return None

        root = TreeNode(node_val)

        if height > 1:
            root.left = self.buildTree(2 * node_val, height - 1)
            root.right = self.buildTree(2 * node_val + 1, height - 1)

        return root

soluzione = Solution()
depth = 10
nPalline = 1
head = soluzione.buildTree(1, depth)
print(soluzione.getLastSpot(head, nPalline, depth))