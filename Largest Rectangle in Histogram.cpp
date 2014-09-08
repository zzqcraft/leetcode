class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        
        if (height.empty ())
        {
            return 0;
        }
        else
        {
            stack<int> myStack;
            
            myStack.push (0);
            height.push_back (0);
            size_t result = 0;
            
            for (size_t i = 1; i < height.size (); i++)
            {
                if (myStack.empty () || height[myStack.top ()] < height[i])
                {
                    myStack.push (i);
                }
                else
                {
                    int leftMost = myStack.top ();
                    
                    myStack.pop ();
                    
                    result = max (result, height[leftMost] * (myStack.empty () ? i : i - myStack.top () - 1));
                    
                    i--;
                }
            }
            
            return result;
        }
    }
};
