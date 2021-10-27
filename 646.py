class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        
        sorted_pairs = sorted(pairs)
        
        print(sorted_pairs)
        
        cache = []
        
        result = 0
        
        for pair in sorted_pairs:
            if len(cache) == 0:
                cache.append(1)
                result = 1
            else:
                val = 0
                for i in range(len(cache)):
                    if sorted_pairs[i][1] < pair[0]:
                        val = max(val, cache[i] + 1)
                    else:
                        val = max(val, cache[i])
                cache.append(val)
                result = max(result, val)
        
                        
        return result
