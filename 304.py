class NumMatrix:

    
    def __init__(self, matrix: List[List[int]]):
        self.cache = []
        for i, li in enumerate(matrix):
            newList = []
            for j, val in enumerate(li):
                newVal = val
                if i > 0:
                    newVal += self.cache[i - 1][j]
                if j > 0:
                    newVal += newList[j - 1]
                if i > 0 and j > 0:
                    newVal -= self.cache[i - 1][j - 1]

                newList.append(newVal)
            self.cache.append(newList)
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        result = self.cache[row2][col2]
        if row1 > 0:
            result -= self.cache[row1 - 1][col2]
        if col1 > 0:
            result -= self.cache[row2][col1 - 1]
        if row1 > 0 and col1 > 0:
            result += self.cache[row1 - 1][col1 - 1]
        return result


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
