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
    int maxd=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int lenl = dept(root->left, 0);
        int lenr = dept(root->right, 0);
        // cout<<lenl<<','<<lenr<<endl;
        
        maxd = max(maxd, lenl+lenr);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxd;
    }
    int dept(TreeNode* root, int d){
        if(!root)
            return d;
        return max(dept(root->left,d+1), dept(root->right, d+1));
    }
};