from sortedcontainers import SortedList
'''
Inspired from https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/1313721/JavaPython-Sub-problem%3A-Max-Sum-of-Subarray-No-Larger-Than-K-Clean-and-Concise
'''
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        result = -math.inf
        for i in range(len(matrix)):
            arr = [0] * len(matrix[0])
            for j in range(i, len(matrix)):
                for l in range(len(matrix[0])):
                    arr[l] += matrix[j][l]
                result = max(result, self.maxMatrixSize(arr, k))
        return result
        
    def maxMatrixSize(self, arr: List[int], k: int) -> int:
        result = -math.inf
        sortedList = SortedList([0])
        curr = 0
        for val in arr:
            curr += val
            ceil = self.ceiling(sortedList, curr - k)
            if ceil is not None:
                result = max(result, curr - ceil)
            sortedList.add(curr)
        return result
        
    def ceiling(self, sortedList: SortedList[int], key: int) -> Optional[int]:
        idx = sortedList.bisect_left(key)
        if idx < len(sortedList): return sortedList[idx]
        return None
