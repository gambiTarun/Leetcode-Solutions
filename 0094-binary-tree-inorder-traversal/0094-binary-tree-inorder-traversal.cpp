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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris traversal
        
        TreeNode *curr = root;
        vector<int> res;
        
        while(curr){
            // printing leftnode
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{                
                TreeNode *tmp = curr->left;
                while(tmp->right != NULL && tmp->right != curr)
                    tmp = tmp->right;
                // making new connections
                if(tmp->right==NULL){
                    tmp->right=curr;
                    curr=curr->left;
                }
                //removing those connections
                else{
                    tmp->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        
        return res;
    }
};