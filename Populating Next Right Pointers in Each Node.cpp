/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeLinkNode*> prevQueue;
        queue<TreeLinkNode*> currQueue;
        
        if (NULL != root)
        {
            prevQueue.push (root);
        }
        
        while (prevQueue.size () > 0)
        {
            TreeLinkNode* lastNode = NULL;
            
            while (prevQueue.size () > 0)
            {
                TreeLinkNode* currNode = prevQueue.front ();
                
                if (NULL != lastNode)
                {
                    lastNode->next = currNode;
                }
                
                lastNode = currNode;
                
                if (NULL != currNode->left)
                {
                    currQueue.push (currNode->left);
                }
                
                if (NULL != currNode->right)
                {
                    currQueue.push (currNode->right);
                }
                
                prevQueue.pop ();
            }
            
            swap (prevQueue, currQueue);
        }
    }
};
