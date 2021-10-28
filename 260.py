class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        for a in nums:
            xor = xor ^ a
        separator = (xor & (xor - 1)) ^ xor
        
        start = 0
        end = len(nums) - 1
        
        while start < end:
            if nums[start] & separator == 0:
                start += 1
            elif nums[end] & separator > 0:
                end -= 1
            else:
                tmp = nums[start]
                nums[start] = nums[end]
                nums[end] = tmp

        first = 0
        for i in range(end):
            first = first ^ nums[i]
        
        second = 0
        for i in range(end, len(nums)):
            second = second ^ nums[i]
        
        return [first, second]
