class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        maxPos = 0
        result = [None] * len(nums)
        for i, val in enumerate(nums):
            if nums[maxPos] < val:
                maxPos = i
        
        stack = [maxPos]
        pos = (maxPos + 1) % len(nums)
        
        while pos != maxPos:
            while nums[stack[-1]] < nums[pos]:
                result[stack[-1]] = nums[pos]
                stack.pop()
            stack.append(pos)
            pos = (pos + 1) % len(nums)
        
        while stack:
            p = stack.pop()
            if nums[p] == nums[maxPos]:
                result[p] = -1
            else:
                result[p] = nums[maxPos]
        
        return result
