class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n < 2:
            return pow(10, n)
        else:
            cache = [1, 10]
            
            for i in range(2, n + 1):
                next = 9
                for j in range(1, i):
                    next *= (10 - j)
                next += cache[i - 1]
                cache.append(next)
            
            return cache[n]
