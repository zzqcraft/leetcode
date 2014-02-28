class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int result = 0;
        bool isBuy = true;
        int buyPos = -1;
        
        for (unsigned int i = 1; i < prices.size (); i++)
        {
            if (isBuy)
            {
                if (prices[i] > prices[i - 1])
                {
                    isBuy = false;
                    buyPos = i - 1;
                }
            }
            else
            {
                if (prices[i] < prices[i - 1])
                {
                    result += prices[i - 1] - prices[buyPos];
                    isBuy = true;
                }
            }
        }
        
        if (!isBuy)
        {
            result += prices[prices.size () - 1] - prices[buyPos];
        }
        
        return result;
    }
};
