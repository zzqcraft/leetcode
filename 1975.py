class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        numOfN = 0
        absMin = 100000
        result = 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                absMin = min(absMin, abs(matrix[i][j]))
                result += abs(matrix[i][j])
                if (matrix[i][j] < 0):
                    numOfN += 1
        if numOfN % 2 == 0:
            return result
        else:
            return result - (absMin * 2)
