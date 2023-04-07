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
    int maxAncestorDiff(TreeNode* root) {
        int res=0;
        explore(root,res);
        return res;
    }
    
    void explore(TreeNode *root, int &res){
        if(!root)
            return;
        
        dfs(root->left,res,root->val);
        dfs(root->right,res,root->val);
        
        explore(root->left,res);
        explore(root->right,res);
        
    }
    
    void dfs(TreeNode *node, int &res, int rv){
        if(!node)
            return;
        
        dfs(node->left,res,rv);
        dfs(node->right,res,rv);
        res = max(res,abs(rv-node->val));
    }
};