class Solution {
    void findAllSol (vector<int>& num, int start, int target, vector<vector<int>>& output)
    {
        int end     = num.size () - 1;
        
        while (start < end)
        {
            int second = num[start];
            int last   = num[end];
            int temp   = second + last;
            
            if (temp == target)
            {
                vector<int> tempVec;
                
                tempVec.push_back (0 - target);
                tempVec.push_back (second);
                tempVec.push_back (last);
                
                output.push_back (tempVec);
                
                start++;
                end--;
                
                while (start < end && num[start] == second)
                {
                    start++;
                }
                
                while (start < end && num[end] == last)
                {
                    end--;
                }
            }
            else if (temp < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        int                 index = 0;
        
        sort (num.begin (), num.end ());
        
        while (index + 2 < num.size ())
        {
            findAllSol (num, index + 1, 0 - num[index], result);
            
            index++;
            
            while (index + 2 < num.size () && num[index] == num[index - 1])
            {
                index++;
            }
        }
        
        return result;
    }
};
