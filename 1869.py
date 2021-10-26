class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        max1 = 0
        max0 = 0
        cur1 = 0
        cur0 = 0
        
        for c in s:
            if c == '1':
                max0 = max(max0, cur0)
                cur0 = 0
                cur1 += 1
            else:
                max1 = max(max1, cur1)
                cur1 = 0
                cur0 += 1
        
        max0 = max(max0, cur0)
        max1 = max(max1, cur1)
        return max1 > max0
