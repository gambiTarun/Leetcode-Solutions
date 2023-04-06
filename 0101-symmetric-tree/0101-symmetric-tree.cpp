/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return equal(root->left,root->right);
    }
    bool equal(TreeNode*a, TreeNode*b){
        if(a==NULL && b==NULL)
            return true;
        if(a==NULL || b==NULL)
            return false;
        
        return a->val==b->val && equal(a->left,b->right) && equal(a->right,b->left);
    }
};