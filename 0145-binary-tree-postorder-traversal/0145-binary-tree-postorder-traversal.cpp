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
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        
        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* tmp = st.top()->right;
                if(!tmp){
                    tmp = st.top();
                    st.pop();
                    res.push_back(tmp->val);
                    while(!st.empty() && tmp==st.top()->right){
                        tmp = st.top();
                        st.pop();
                        res.push_back(tmp->val);
                    }
                }
                else
                    curr=tmp;
            }
        }
        return res;
    }
};