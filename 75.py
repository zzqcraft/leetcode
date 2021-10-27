class Solution:
    def swap(self, nums: List[int], pos1: int, pos2: int) -> None:
        tmp = nums[pos1]
        nums[pos1] = nums[pos2]
        nums[pos2] = tmp
    
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        pos0 = 0
        pos1 = 0
        pos2 = len(nums) - 1
        
        while pos1 <= pos2:
            if nums[pos0] == 0:
                pos0 += 1
                pos1 = max(pos0, pos1)
            elif nums[pos1] == 1:
                pos1 += 1
            elif nums[pos2] == 2:
                pos2 -= 1
            else:
                if (nums[pos1] == 0):
                    self.swap(nums, pos0, pos1)
                    pos0 += 1
                    pos1 = max(pos0, pos1)
                elif nums[pos2] == 1:
                    self.swap(nums, pos1, pos2)
                    pos1 += 1
                else:
                    self.swap(nums, pos0, pos2)
                    pos0 += 1
                    pos1 = max(pos0, pos1)
