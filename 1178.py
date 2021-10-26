class Solution:
    def encodeString(self, word: str) -> int:
        result = 0
        for c in word:
            result = result | (1 << (ord(c) - ord('a')))
        return result
    
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        wordCache = Counter(map(self.encodeString, [w for w in words if len(set(w)) <= 7]))        
        
        result = []
        
        for p in puzzles:
            allMasks = [self.encodeString(p[0])]
            # this is the tricky part, we will generate all possible encodings and look up in the dictionary (total number of mask per puzzle is 2^6)
            for c in p[1:]:
                newMasks = copy.copy(allMasks)
                for i in range(len(newMasks)):
                    newMasks[i] |= 1 << (ord(c) - ord('a'))
                allMasks.extend(newMasks)
            
            match = 0
            
            for m in allMasks:
                match += wordCache[m]
            result.append(match)
            
        return result
