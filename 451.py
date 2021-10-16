class Solution:
    def frequencySort(self, s: str) -> str:
        ct = Counter(s)
        return ''.join(x * ct[x] for x in sorted(ct, key = lambda x :ct[x], reverse=True))
