class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        cache = []
        for i in range(len(indices)):
            cache.append([indices[i], sources[i], targets[i]])
        cache.sort()
        
        result = ""
        nextPos = 0
        for var in cache:
            result += s[nextPos:var[0]]
            nextPos = var[0]
            if len(var[1]) + var[0] <= len(s):
                if (s[var[0]:var[0] + len(var[1])]) == var[1]:
                    result += var[2]
                    nextPos += len(var[1])
                
        result += s[nextPos:]
        return result
