class Solution {
    void PackLine (vector<string>& input, vector<string>& output, int L)
    {
        int sizeOfSpace = L;
        string result;
        
        for (auto s : input)
        {
            sizeOfSpace -= s.size ();
        }
        
        sizeOfSpace -= (input.size () - 1);
        
        for (int i = 0; i < (int)(input.size ()) - 1; i++)
        {
            int spaceAfter = 0;
            
            if (sizeOfSpace > 0)
            {
                spaceAfter = (sizeOfSpace - 1) / (input.size () - i - 1) + 1;
            }
            
            sizeOfSpace -= spaceAfter;
            result      += input[i] + " ";
            
            for (int j = 0; j < spaceAfter; j++)
            {
                result += " ";
            }
        }
        
        result += input[input.size () - 1];
        
        for (int j = 0; j < sizeOfSpace; j++)
        {
            result += " ";
        }
        
        output.push_back (result);
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string>  result;
        
        if (words.size () > 0)
        {
            vector<string>  temp;
            int             spaceLeft = L;
            
            
            for (auto s : words)
            {
                if ((int) (s.size ()) <= spaceLeft)
                {
                    temp.push_back (s);
                    spaceLeft -= (s.size () + 1);
                }
                else
                {
                    PackLine (temp, result, L);
                    
                    temp.clear ();
                    spaceLeft = L;
                    
                    if ((int) (s.size ()) <= spaceLeft)
                    {
                        temp.push_back (s);
                        spaceLeft -= s.size () + 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
            if (temp.size () > 0)
            {
                string tmp;
                
                for (int i = 0; i < (int)(temp.size ()) - 1; i++)
                {
                    tmp += temp[i] + " ";
                }
                tmp += temp[temp.size () - 1];
                
                int numOfSpace = L - tmp.size ();
                
                for (int i = 0; i < numOfSpace; i++)
                {
                    tmp += " ";
                }
                
                result.push_back (tmp);
            }
        }
        
        return result;
    }
};
