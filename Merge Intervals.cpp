/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval i1, Interval i2)
{  
    return (i1.start < i2.start) ? true: false; 
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval> result;
        
        if (intervals.size () == 0)
        {
            return result;
        }
        else
        {
            int startVal;
            int endVal;
            
            sort(intervals.begin(), intervals.end(), compareInterval);
            
            startVal = intervals[0].start;
            endVal = intervals[0].end;
            
            for (unsigned int i = 1; i < intervals.size (); i++)
            {
                if (intervals[i].start <= endVal)
                {
                    endVal = max (endVal, intervals[i].end);
                }
                else
                {
                    result.emplace_back (startVal, endVal);
                    startVal = intervals[i].start;
                    endVal = intervals[i].end;
                }
            }
            
            result.emplace_back (startVal, endVal);
            
            return result;
        }
    }
};
