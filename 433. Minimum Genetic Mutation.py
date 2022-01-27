import queue

class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        
        steps = 0
        
        if start == end:
            return steps
        
        push_q = queue.Queue()
        pop_q = queue.Queue()
        visited = set()
        
        pop_q.put(start)
        
        while not pop_q.empty():
            steps += 1
            while not pop_q.empty():
                candid = pop_q.get()
                for i in range(8):
                    for c in ['A', 'C', 'G', 'T']:
                        if candid[i] != c:
                            newStr = candid[:i] + c + candid[i + 1:]
                            if newStr not in bank:
                                continue
                            if newStr == end:
                                return steps
                            if newStr not in visited:
                                visited.add(newStr)
                                push_q.put(newStr)
            pop_q = push_q
            push_q = queue.Queue()
        
        return -1
