class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        const char* lastWildCard = NULL;
        const char* lastS        = NULL;
        
        while (true)
        {
            if (*p == '*')
            {
                lastWildCard = p++;
                lastS = s;
            }
            else if (*p == '\0')
            {
                if (*s == '\0')
                {
                    return true;
                }
                else if (NULL == lastWildCard)
                {
                    return false;
                }
                else
                {
                    p = lastWildCard + 1;
                    s = ++lastS;
                }
            }
            else if (*s == '\0')
            {
                return false;
            }
            else if (*p == *s || *p == '?')
            {
                p++;
                s++;
            }
            else if (NULL == lastWildCard)
            {
                return false;
            }
            else
            {
                p = lastWildCard + 1;
                s = ++lastS;
            }
        }
    }
};
