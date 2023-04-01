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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        if(invalleft(root->left, root) || invalright(root->right, root))
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
    
    int invalleft(TreeNode *node, TreeNode *root){
        if(!node)
            return false;
        while(node->right)
            node=node->right;
        return node->val >= root->val;
    }
    
    int invalright(TreeNode *node, TreeNode *root){
        if(!node)
            return false;
        while(node->left)
            node=node->left;
        return node->val <= root->val;
    }
};