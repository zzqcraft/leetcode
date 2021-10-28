class Solution:
    
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        flatten = sorted(sum(matrix, []))
        return flatten[k - 1]
