class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        
        profit = 0
        maxProfit = -1
        rounds = 0
        result = 0
        waiting = 0
        
        for w in customers:
            waiting += w
                
            if waiting >= 4:
                profit += (4 * boardingCost - runningCost)
                rounds += 1
                waiting -= 4
            else:
                profit += (waiting * boardingCost - runningCost)
                rounds += 1
                waiting = 0
            if profit > maxProfit:
                result = rounds
                maxProfit = profit
        
        while waiting > 0:
            if waiting >= 4:
                profit += (4 * boardingCost - runningCost)
                rounds += 1
                waiting -= 4
            else:
                profit += (waiting * boardingCost - runningCost)
                rounds += 1
                waiting = 0
            if profit > maxProfit:
                result = rounds
                maxProfit = profit
        
        if maxProfit > 0:
            return result
        else:
            return -1
