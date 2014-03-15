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
    bool isValidBST (TreeNode* root, int rangeLow, int rangeHigh)
    {
        if (NULL == root)
        {
            return true;
        }
        else if (root->val >= rangeHigh || root->val <= rangeLow)
        {
            return false;
        }
        else
        {
            return isValidBST (root->left, rangeLow, root->val) && isValidBST (root->right, root->val, rangeHigh);
        }
    }
public:
    bool isValidBST(TreeNode *root) {
        
        return isValidBST (root, INT_MIN, INT_MAX);
    }
};
