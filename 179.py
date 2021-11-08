class Solution:
        def largestNumber(self, nums: List[int]) -> str:

                    if all(val == 0 for val in nums):
                                    return "0"

                                        return ''.join(sorted(map(str, nums), key=cmp_to_key(lambda l1, l2: int(l2 + l1) - int(l1 + l2))))
