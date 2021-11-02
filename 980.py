class Solution:
    def internal(self, x: int, y: int, remaining: int, grid: List[List[int]]) -> int:
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]):
            return 0
        
        if remaining == 0:
            if grid[x][y] == 2:
                return 1
            else:
                return 0
        elif grid[x][y] != 0 and grid[x][y] != 1:
            return 0
        else:
            old_val = grid[x][y]
            grid[x][y] = 3
            result = self.internal(x - 1, y, remaining - 1, grid) + self.internal(x + 1, y, remaining - 1, grid) + self.internal(x, y - 1, remaining - 1, grid) + self.internal(x, y + 1, remaining - 1, grid)
            grid[x][y] = old_val
            return result
        
        
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        remaining = 0
        x = -1
        y = -1
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    x = i
                    y = j
                elif grid[i][j] == 0:
                    remaining += 1
        
        return self.internal(x, y, remaining + 1, grid)
        
