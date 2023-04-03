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
        bool notbalnced=false;
        longest(root,notbalnced);
        return !notbalnced;
    }
    
    int longest(TreeNode*node, bool &d){
        if(!node)
            return d;
        int l = longest(node->left,d);
        int r = longest(node->right,d);
        d |= abs(l-r)>1;
        
        return max(l,r)+1;
    }
};