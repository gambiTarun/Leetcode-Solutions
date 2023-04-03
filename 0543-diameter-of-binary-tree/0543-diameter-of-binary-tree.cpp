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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int res=0;
        longest(root,res);
        return res;
    }
    int longest(TreeNode* root, int &dia){
        if(!root)
            return 0;
        int lenl = longest(root->left, dia);
        int lenr = longest(root->right, dia);
        dia = max(dia, lenl+lenr);
        return max(lenl,lenr)+1;
    }
};