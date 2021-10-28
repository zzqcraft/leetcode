class Solution:
    def maxPower(self, s: str) -> int:
        result = 1
        curr = 1
        
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                curr += 1
                result = max(result, curr)
            else:
                curr = 1
        return result
