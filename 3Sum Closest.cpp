class Solution {
    int Closest (vector<int>& num, int end, int target)
    {
        int start  = 0;
        int result = num[start] + num[end];
        
        while (start < end)
        {
            int temp = num[start] + num[end];
            
            if (temp == target)
            {
                return target;
            }
            else
            {
                if (abs (temp - target) < abs (result - target))
                {
                    result = temp;
                }
                
                if (temp < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        
        return result;
    }
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        if (num.size () < 3)
        {
            return -1;
        }
        else
        {
            sort (num.begin (), num.end ());
            
            int result = num[0] + num[1] + num[2];
            
            for (int i = num.size () - 1; i > 2; i--)
            {
                int temp = Closest (num, i - 1, target - num[i]);
                
                if (abs (target - result) > abs (target - num[i] - temp))
                {
                    result = temp + num[i];
                }
            }
            
            return result;
        }
    }
};
