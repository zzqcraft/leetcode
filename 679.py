class Solution:
    def calculate(self, a: float, b: float) -> set[float]:
        result = set()
        
        result.add(a + b)
        result.add(a - b)
        result.add(b - a)
        result.add(a * b)
        if b != 0:
            result.add(a / b)
        if a != 0:
            result.add(b / a)
        return result
        
        
    def judgePoint24(self, cards: List[int]) -> bool:
             
        cache = dict()
        
        for i in range(16):
            cache[i] = set()
        
        for i in range(4):
            cache[1 << i].add(cards[i])
            
        for i in range(4):
            for j in range(i + 1, 4):
                cache[(1 << i) + (1 << j)].update(self.calculate(cards[i], cards[j]))
                for k in range(4):
                    if k == i or k == j:
                        continue
                    idx = (1 << i) + (1 << j) + (1 << k)
                    for val in cache[(1 << i) + (1 << j)]:
                        cache[idx].update(self.calculate(val, cards[k]))
        
        for i in range(4):
            idx = 15 - (1 << i)
            for val in cache[idx]:
                to_check = self.calculate(cards[i], val)
                if 24 in to_check:
                    return True
                for val3 in to_check:
                    if abs(val3 - 24) < 0.01:
                        return True
                
        for i in range(4):
            for j in range(i + 1, 4):
                idx = 15 - (1 << i) - (1 << j)
                for val in cache[idx]:
                    for val2 in cache[15 - idx]:
                        to_check = self.calculate(val, val2)
                        if 24 in to_check:
                            return True
                        for val3 in to_check:
                            if abs(val3 - 24) < 0.01:
                                return True
        return False
