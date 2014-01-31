/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct MyCompare
{
    bool operator() (ListNode*& lhs, ListNode*& rhs) const
    {
        return (lhs->val > rhs->val);
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode*, std::vector<ListNode*>, MyCompare> min_heap;
        ListNode*                          result = NULL;
        ListNode*                          tail   = NULL;
        
        for (int i = 0; i < lists.size (); i++)
        {
            if (NULL != lists[i])
            {
                min_heap.push (lists[i]);
            
                lists[i] = lists[i]->next;
            }
        }
        
        while (!min_heap.empty ())
        {
            ListNode* temp = min_heap.top ();
            
            min_heap.pop ();
            
            if (NULL == result)
            {
                result = temp;
                tail   = result;
            }
            else
            {
                tail->next = temp;
                tail       = tail->next;
            }
            
            temp = temp->next;
            
            if (NULL != temp)
            {
                min_heap.push (temp);
            }
        }
        
        
        return result;
    }
};
