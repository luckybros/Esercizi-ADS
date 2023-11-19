# La ricorrenza è esprimibile nella forma T(n) = 2T(n/2) + O(n), dunque,
# la complessità è pari ad O(n*logn).


class Solution:
    def maximumSubarray(self, nums, left, right):
        if left >= right:
            return nums[left]
        
        middle = (left + right)//2
        leftMax = self.maximumSubarray(nums, left, middle)
        rightMax = self.maximumSubarray(nums, middle+1, right)
        return self.calcSum(nums, left, middle, right, leftMax, rightMax)
    
    def calcSum(self, nums, left, middle, right, leftMax, rightMax):
        leftSum = float('-inf')
        sum = 0
        for i in range(middle, left-1, -1):
            sum += nums[i]
            if leftSum < sum:
                leftSum = sum
        rightSum = float('-inf')
        sum = 0
        for i in range(middle+1, right+1):
            sum += nums[i]
            if rightSum < sum:
                rightSum = sum
        return max(leftMax, rightMax, leftSum+rightSum)

def read_vectors(filename):
    vectors = []
    with open(filename, 'r') as file:
        for line in file:
            if line.strip() == 'END':
                break
            vector = [int(val) for val in line.strip().split() if val != '-']
            vectors.append(vector)
    return vectors

input_filename = 'input.txt'
solution = Solution()
vectors = read_vectors(input_filename)

for nums in vectors:
    result = solution.maximumSubarray(nums, 0, len(nums) - 1)
    print(result)
    
    