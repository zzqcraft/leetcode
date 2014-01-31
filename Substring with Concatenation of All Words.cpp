class Solution {  
public:  
    vector<int> findSubstring(string S, vector<string> &L) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function
        vector<int> result;
        
        if (L.size () == 0)
        {
            return result;
        }
        else
        {
            unordered_map<string, int> words;
            unordered_map<string, int> temp;
            int wordCount  = L.size ();
            int wordLength = L[0].size ();               
            
            for (auto s : L)
            {
                ++words[s];
            }
            
            for (int i = 0; i <= ((int)S.size () - wordCount * wordLength); i++)
            {
                bool found = true;

                temp.clear ();
                
                for (int j = 0; j < wordCount; j++)
                {
                    string w = S.substr (i + j * wordLength, wordLength);
                    
                    if (words.count (w) == 0)
                    {
                        found = false;
                        break;
                    }
                    else
                    {
                        ++temp[w];
                        
                        if (temp[w] > words[w])
                        {
                            found = false;
                            break;
                        }
                    }
                }
                
                if (found)
                {
                    result.push_back (i);
                }
            }
        }
        
        return result;
    }  
}; 
