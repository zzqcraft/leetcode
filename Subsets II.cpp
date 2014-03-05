class Solution {
    void findSubset (vector<int>& S, vector<vector<int>>& output, int currentIdx, vector<int>& prefix)
    {
        output.push_back (prefix);
        
        if (currentIdx < S.size ())
        {
            int lastVal = 0;
            bool isValidLastVal = false;
            
            for (unsigned int i = currentIdx; i < S.size (); i++)
            {
                if (isValidLastVal)
                {
                    if (S[i] == lastVal)
                    {
                        continue;
                    }
                    else
                    {
                        lastVal = S[i];
                    }
                }
                else
                {
                    lastVal = S[i];
                    isValidLastVal = true;
                }
                
                prefix.push_back (lastVal);
                findSubset (S, output, i + 1, prefix);
                prefix.pop_back ();
            }
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        
        if (S.size () > 0)
        {
            vector<int> prefix;
        
            sort (S.begin (), S.end ());
            
            findSubset (S, result, 0, prefix);
        }
        
        return result;
    }
};
