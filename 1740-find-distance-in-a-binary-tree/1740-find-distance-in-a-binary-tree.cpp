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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* node=lca(root,p,q);
        // cout<<dis(node,p,0)<<endl;
        // cout<<dis(node,q,0)<<endl;
        return dis(node,p,0)+dis(node,q,0);
    }
    
    int dis(TreeNode* r, int x, int d){
        if(!r)
            return 0;
        if(r->val==x)
            return d;
        return dis(r->left,x,d+1)+dis(r->right,x,d+1);
    }
    
    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root || root->val==p || root->val==q){
            return root;
        }
        
        TreeNode* l = lca(root->left,p,q);
        TreeNode* r = lca(root->right,p,q);
        
        return l&&r?root:(l?l:r);
    }
};