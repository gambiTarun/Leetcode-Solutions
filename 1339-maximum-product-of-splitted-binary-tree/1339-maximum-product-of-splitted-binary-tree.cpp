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
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        int tsum = getsum(root);
        long maxp=0;
        
        maxhelper(root,tsum,maxp);
        return (int) (maxp % 1000000007);
    }
    
    int getsum(TreeNode* root){
        if(!root)
            return 0;
        return root->val + getsum(root->left) + getsum(root->right);
    }
    
    int maxhelper(TreeNode*root, int tsum, long &res){
        if(!root)
            return 0;
        
        int lsum = maxhelper(root->left,tsum,res);
        int rsum = maxhelper(root->right,tsum,res);
        long totsum = lsum + rsum + root->val;
        
        res = max(res, (long) totsum*(tsum-totsum));
        
        return totsum;
    }
};