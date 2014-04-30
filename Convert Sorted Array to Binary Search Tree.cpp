/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct QueueElement
{
    TreeNode* root;
    int min;
    int max;
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (num.size () == 0)
        {
            return NULL;
        }
        else
        {
            queue<QueueElement*> myQueue;
            int min = 0;
            int max = num.size () - 1;
            int mid = max / 2;
            TreeNode* result = new TreeNode (num [mid]);
            TreeNode* root = result;
            
            while (true)
            {
                if (min < max)
                {
                    mid = (min + max) / 2;
                    
                    if (min < mid)
                    {
                        QueueElement* next = new QueueElement();
                        next->root = new TreeNode (num[(min + mid - 1) / 2]);
                        next->min = min;
                        next->max = mid - 1;
                        
                        root->left = next->root;
                        myQueue.push (next);
                    }
                    
                    if (mid < max)
                    {
                        QueueElement* next = new QueueElement();
                        next->root = new TreeNode (num[(mid + max + 1) / 2]);
                        next->min = mid + 1;
                        next->max = max;
                        
                        root->right = next->root;
                        myQueue.push (next);
                    }
                }
                
                if (myQueue.size () > 0)
                {
                    QueueElement* current = myQueue.front ();
                    myQueue.pop ();
                    
                    min = current->min;
                    max = current->max;
                    root = current->root;
                    
                    delete current;
                }
                else
                {
                    break;
                }
            }
            
            return result;
        }
    }
};
