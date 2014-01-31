class Solution {
    char AddChar (char first, char second, int addition, int& plusOne)
    {
        int firstInt  = first - '0';
        int secondInt = second - '0';
        int result    = firstInt + secondInt + addition;
        
        plusOne = result / 10;
        result  = result % 10;
        
        return ('0' + result);
    }

    char MultipleChar (char first, char second, int& addition)
    {
        int firstInt  = first - '0';
        int secondInt = second - '0';
        int result    = firstInt * secondInt;
        
        if (result >= 10)
        {
            addition = result / 10;
            result   = result % 10;
        }
        else
        {
            addition = 0; 
        }
        
        return ('0' + result);
    }
public:
    string multiply(string num1, string num2) {
        if (num1.compare ("0") == 0 || num2.compare("0") == 0)
        {
            string result = "0";
            
            return result;
        }
        else
        {
            vector<char> buffer (num1.size () + num2.size ());
            
            
            
            for (int i = 0; i < buffer.size (); i++)
            {
                buffer[i] = '0';
            }
            
            for (int i = num1.size () - 1; i >= 0; i--)
            {
                int addition = 0;

                for (int j = num2.size () - 1; j >= 0; j--)
                {
                    int  localAdd = 0;
                    int  plusOne  = 0;
                    char localSum = MultipleChar (num1[i], num2[j], localAdd);
                    
                    buffer [i + j + 1] = AddChar (localSum, buffer [i + j + 1], addition, plusOne);
                    
                    addition = localAdd + plusOne;
                }

                if (addition > 0)
                {
                    buffer [i] = '0' + addition;  
                }
            }
            
            if (buffer[0] != '0')
            {
                return string (buffer.begin(), buffer.end ());
            }
            else
            {
                return string (buffer.begin () + 1, buffer.end ());
            }
        }
    }
};
