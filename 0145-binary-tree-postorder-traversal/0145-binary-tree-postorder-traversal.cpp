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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *curr=root;
        vector<int> res;
        while(curr){
            if(curr->right==NULL){
                res.push_back(curr->val);
                curr=curr->left;
            }
            else{
                TreeNode *pred = curr->right;
                while(pred->left!=NULL && pred->left!=curr)
                    pred = pred->left;
                if(pred->left==NULL){
                    pred->left=curr;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
                else{
                    pred->left = NULL;
                    curr=curr->left;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};