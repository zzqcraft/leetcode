struct MyPrefix
{
    int depth;
    unordered_set<string> fathers;
};


class Solution {
    void setToResult (unordered_map<string,MyPrefix>& father, stack<string>& history, vector<vector<string>>& output)
    {
        string candidate = history.top ();
        
        if (father.count (candidate) > 0 && father[candidate].fathers.size () > 0)
        {
            for (auto s : father[candidate].fathers)
            {
                history.push(s);
                setToResult (father, history, output);
                history.pop();
            }
        }
        else
        {
            vector<string> temp;
            
            temp.push_back (candidate);
        
            while (history.size () > 0)
            {
                candidate = history.top ();
                
                history.pop ();
                temp.push_back (candidate);
            }
            
            output.push_back (temp);
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        unordered_map<string,MyPrefix> father;
        unordered_set<string> setToPush;
        unordered_set<string> setToPop;
        stack<string> first;
        int           length = 1;
        bool          stopHere = false;
        vector<vector<string>> result;
        
        father[start].depth = length;
        
        setToPop.insert(start);
        
        while (setToPop.size () > 0)
        {
            for (auto last : setToPop)
            {
                for (int i = 0; i < last.size (); i++)
                {
                    string candidate = last;
                    
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c != last[i])
                        {
                            candidate[i] = c;
                            
                            if (candidate == end)
                            {
                                if (father.count (candidate) == 0)
                                {
                                    father[candidate].depth = length;
                                    father[candidate].fathers.insert (last);
                                }
                                else if (father[candidate].depth == length)
                                {
                                    father[candidate].fathers.insert (last);
                                }
                                
                                stack<string> temp;
                                
                                temp.push (end);
                                
                                setToResult (father, temp, result);
                                
                                stopHere = true;
                                
                                break;
                            }
                            else if (!stopHere && dict.count (candidate) > 0)
                            {
                                if (father.count (candidate) == 0)
                                {
                                    father[candidate].depth = length;
                                    father[candidate].fathers.insert (last);
                                    
                                    setToPush.insert (candidate);
                                }
                                else if (father[candidate].depth == length)
                                {
                                    father[candidate].fathers.insert (last);
                                    
                                    setToPush.insert (candidate);
                                }
                            }
                        }
                    }
                }
            }
            
            if (stopHere)
            {
                break;
            }
            else
            {
                length++;
                
                setToPop.clear ();
                
                swap (setToPop, setToPush);
            }
        }
        
        return result;
    }
};
