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
        int l = longest(root->left,0);
        int r = longest(root->right,0);
        return abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int longest(TreeNode*node, int d){
        if(!node)
            return d;
        return max(longest(node->left,d+1),longest(node->right,d+1));
    }
};