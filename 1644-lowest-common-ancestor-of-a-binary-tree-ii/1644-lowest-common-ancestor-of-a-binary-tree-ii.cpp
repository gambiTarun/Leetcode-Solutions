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
        bool fp=false,fq=false;
        TreeNode *n = dfs(root,p,q,fp,fq);
        return fp&&fq?n:nullptr;
    }
    TreeNode* dfs(TreeNode*root, TreeNode*p, TreeNode*q, bool &fp, bool &fq){
        if(!root)
            return root;
        if(root==p){
            fp=true;
            if(!fq){
                dfs(root->left,p,q,fp,fq);
                dfs(root->right,p,q,fp,fq);
            }
            return root;
        }
        if(root==q){
            fq=true;
            if(!fp){
                dfs(root->left,p,q,fp,fq);
                dfs(root->right,p,q,fp,fq);
            }
            return root;
        }
        
        TreeNode *l = dfs(root->left,p,q,fp,fq);
        TreeNode *r = dfs(root->right,p,q,fp,fq);
        
        return l&&r?root:(l?l:r);
    }
};