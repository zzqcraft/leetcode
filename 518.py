class Solution:
    def changeInternal(self, remaining: int, coins: List[int], coin_pos: int, cache: List[List[int]]) -> int:
        #print("entering [" + str(coin_pos) + "," + str(remaining) +"]")
        if remaining == 0:
            return 1
        if coin_pos >= len(coins):
            return 0
        
        if cache[coin_pos][remaining] != -1:
            return cache[coin_pos][remaining]
        
        result = self.changeInternal(remaining, coins, coin_pos + 1, cache)
        j = coins[coin_pos]
        while remaining >= j:
            result += self.changeInternal(remaining - j, coins, coin_pos + 1, cache)
            j += coins[coin_pos]
        cache[coin_pos][remaining] = result
        return result
        
        
    def change(self, amount: int, coins: List[int]) -> int:
        cache = [[-1 for i in range(amount + 1)] for j in range(len(coins))]
        return self.changeInternal(amount, coins, 0, cache)
