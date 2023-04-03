/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        
        bool leftq = find(root->left,q);
        bool leftp = find(root->left,p);
        
        if(leftq ^ leftp || root==p || root==q)
            return root;
        
        return leftp?lowestCommonAncestor(root->left,p,q):lowestCommonAncestor(root->right,p,q);
    }
    
    bool find(TreeNode* root, TreeNode* x){
        if(!root)
            return false;
        return root==x || find(root->left,x) || find(root->right,x);
    }
};