class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        valDict = {}
        maxLen = 0
        maxSet = set()
        
        for i in range(len(nums)):
            lens = 0
            if nums[i] in valDict.keys():
                lens = valDict[nums[i]][0] + 1
                valDict[nums[i]][0] = lens
                valDict[nums[i]][2] = i - valDict[nums[i]][1] + 1
            else:
                lens = 1
                valDict[nums[i]] = [1, i, 1]
                
            if lens > maxLen:
                maxLen = lens
                maxSet.clear()
                maxSet.add(nums[i])
            elif lens == maxLen:
                maxSet.add(nums[i])
                
        result = 50001
        for l in maxSet:
            result = min(result, valDict[l][2])
        return result
