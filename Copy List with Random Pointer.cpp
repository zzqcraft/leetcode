/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> nodeMap;
        RandomListNode* result = NULL;
        RandomListNode* sourceCursor = head;
        RandomListNode* targetCursor = NULL;
        
        nodeMap[NULL] = NULL;
        
        while (NULL != sourceCursor)
        {
            RandomListNode* temp = new RandomListNode (sourceCursor->label);
            
            nodeMap[sourceCursor] = temp;
            
            if (NULL == result)
            {
                result = temp;
            }
            else
            {
                targetCursor->next = temp;
            }
            
            targetCursor = temp;
            sourceCursor = sourceCursor->next;
        }
        
        sourceCursor = head;
        
        while (NULL != sourceCursor)
        {
            nodeMap[sourceCursor]->random = nodeMap[sourceCursor->random];
            sourceCursor = sourceCursor->next;
        }
        
        return result;
    }
};
