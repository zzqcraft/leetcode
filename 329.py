class Solution:
    def longestIncreasingPrefix(self, x: int, y: int, matrix: List[List[int]], cache: List[List[int]]) -> int:
       if cache[x][y] != -1:
          return cache[x][y]
       else:
          result = 0
          if x > 0 and matrix[x - 1][y] > matrix[x][y]:
            result = self.longestIncreasingPrefix(x - 1, y, matrix, cache)
          if y > 0 and matrix[x][y - 1] > matrix[x][y]:
            result = max(result, self.longestIncreasingPrefix(x, y - 1, matrix, cache))
          if x + 1 < len(matrix) and matrix[x + 1][y] > matrix[x][y]:
            result = max(result, self.longestIncreasingPrefix(x + 1, y, matrix, cache))
          if y + 1 < len(matrix[0]) and matrix[x][y + 1] > matrix[x][y]:
            result = max(result, self.longestIncreasingPrefix(x, y + 1, matrix, cache))
          cache[x][y] = result + 1
          return cache[x][y]
    
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        cache = [[-1 for i in range(len(matrix[0]))] for j in range(len(matrix))]
        result = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                result = max(result, self.longestIncreasingPrefix(i, j, matrix, cache))
        return result
