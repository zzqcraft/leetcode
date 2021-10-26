class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        result = 0
        pos = 0
        
        for l in mat:
            pos2 = len(mat) - pos - 1
            if pos2 != pos:
                result += l[pos2]
            result += l[pos]
            pos += 1
        return result
