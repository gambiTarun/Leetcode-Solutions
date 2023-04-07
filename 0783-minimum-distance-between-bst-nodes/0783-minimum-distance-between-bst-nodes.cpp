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
    int minDiffInBST(TreeNode* root) {
        int res=INT_MAX,prev=INT_MAX;
        inorder(root,res,prev);
        return res;
    }
    
    void inorder(TreeNode *root, int &r, int &p){
        if(!root)
            return;
        
        inorder(root->left,r,p);
        
        r = min(r,abs(root->val-p));
        p = root->val;
        inorder(root->right,r,p);
    }
};