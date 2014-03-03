class Solution {
    
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int currentMin = INT_MAX;
        int result = 0;
        
        for (unsigned int i = 0; i < prices.size (); i++)
        {
            if (prices[i] < currentMin)
            {
                currentMin = prices[i];
            }
            else if (prices[i] - currentMin > result)
            {
                result = prices[i] - currentMin;
            }
        }
        
        return result;
    }
};
