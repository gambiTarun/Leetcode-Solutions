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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool balanced=true;
        depth(root,balanced);
        return balanced;
    }
    
    int depth(TreeNode *root, bool &bal){
        if(!root || !bal)
            return 0;
        
        int l = depth(root->left, bal);
        int r = depth(root->right, bal);
        bal &= abs(l-r)<2;
        
        return max(l,r)+1;
    }
};