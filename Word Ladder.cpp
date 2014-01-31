class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        queue<string> queueToPop;
        queue<string> queueToPush;
        int           distance  = 1;
        
        dict.erase (start);
        dict.erase (end);
        
        queueToPush.push (start);
        
        while (queueToPush.size () > 0)
        {
            swap (queueToPop, queueToPush);
            vector<string> toBeDelete;
            
            while (queueToPop.size () > 0)
            {
                string current = queueToPop.front ();
                
                queueToPop.pop ();
                
                for (int i = 0; i < current.size (); i++)
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (current[i] != c)
                        {
                            string temp = current;
                        
                            temp[i] = c;
                            
                            if (temp.compare (end) == 0)
                            {
                                return (distance + 1);
                            }
                            else if (dict.count (temp) > 0)
                            {
                                queueToPush.push (temp);
                                dict.erase (temp);
                            }
                        }
                    }
                }
            }
            
            for (auto s : toBeDelete)
            {
                dict.erase (s);
            }
            
            distance++;
        }
        
        return 0;
    }
};
