class Solution {
public:
    int romanToInt(string s) {
        
        int strPos = 0;
        int result = 0;
        
        while (strPos < s.size ())
        {
            if (s[strPos] == 'M')
            {
                result += 1000;
            }
            else if (s[strPos] == 'D')
            {
                result += 500;
            }
            else if (s[strPos] == 'C')
            {
                if (strPos + 1 < s.size () && (s[strPos + 1] == 'M' || s[strPos + 1] == 'D'))
                {
                    result -= 100;
                }
                else
                {
                    result += 100;
                }
            }
            else if (s[strPos] == 'L')
            {
                result += 50;
            }
            else if (s[strPos] == 'X')
            {
                if (strPos + 1 < s.size () && (s[strPos + 1] == 'L' || s[strPos + 1] == 'C'))
                {
                    result -= 10;
                }
                else
                {
                    result += 10;
                }
            }
            if (s[strPos] == 'V')
            {
                result += 5;
            }
            else if (s[strPos] == 'I')
            {
                if (strPos + 1 < s.size () && (s[strPos + 1] == 'X' || s[strPos + 1] == 'V'))
                {
                    result -= 1;
                }
                else
                {
                    result += 1;
                }
            }
            
            strPos++;
        }
        
        return result;
    }
};
