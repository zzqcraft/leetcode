/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    ListNode* findBeforeMedian (ListNode* head)
    {
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (NULL == head)
        {
            return NULL;
        }
        else if (NULL == head->next)
        {
            return (new TreeNode (head->val));
        }
        else
        {
            ListNode* tailFirstHalf = findBeforeMedian (head);
            ListNode* treeRoot      = tailFirstHalf->next;
            TreeNode* result        = new TreeNode (treeRoot->val);
            
            tailFirstHalf->next     = NULL;
            result->left            = sortedListToBST (head);
            result->right           = sortedListToBST (treeRoot->next);
            
            return result;
        }
    }
};
