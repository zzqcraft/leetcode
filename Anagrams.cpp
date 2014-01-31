class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, vector<string>> words;
        vector<string> result;
        
        for (auto str : strs)
        {
            string sortedStr = str;
            sort (sortedStr.begin (), sortedStr.end ());
            
            words [sortedStr].push_back (str);
        }
        
        for (auto wordSet : words)
        {
            if (wordSet.second.size () > 1)
            {
                result.insert (result.end (), wordSet.second.begin (), wordSet.second.end ());
            }
        }
        
        return result;
    }
};
