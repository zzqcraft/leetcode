class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        ct = Counter(s)
        uniqueVal = sum([1 for val in ct.values() if val % 2 == 1])
        
        if uniqueVal > k:
            return False
        elif len(s) < k:
            return False
        return True
