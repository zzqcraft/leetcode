import heapq
def new_cmp_lt(a,b):
    if a[0] > b[0]:
        return 1
    elif a[0] < b[0]:
        return -1
    elif a[1] < b[1]:
        return 1
    elif a[1] > b[1]:
        return -1
    return 0

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        
        h = []
        WrapperCls = cmp_to_key(new_cmp_lt)
        
        for ke,ve in Counter(words).items():
            heapq.heappush(h, WrapperCls((ve, ke)))
            if len(h) > k:
                heapq.heappop(h)
        
        res = []        
        while len(h) > 0:
            _, ke = heapq.heappop(h).obj
            
            res.append(ke)
        res.reverse()
            
        return res
