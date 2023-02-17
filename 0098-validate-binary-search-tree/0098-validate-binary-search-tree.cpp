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
private:
    TreeNode* prev=NULL;    
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    bool inorder(TreeNode* r){
        
        if(!r) return true;
        
        if(!inorder(r->left))
            return false;
        
        if(prev && r->val <= prev->val) return false;
        
        prev = r;
        return inorder(r->right);
        
    }
};