class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        mask = 1
        result = 0
        
        for i in range(32):
            count1 = 0
            for val in nums:
                if val & mask > 0:
                    count1 += 1
            result += count1 * (len(nums) - count1)
            mask = mask << 1
        return result
