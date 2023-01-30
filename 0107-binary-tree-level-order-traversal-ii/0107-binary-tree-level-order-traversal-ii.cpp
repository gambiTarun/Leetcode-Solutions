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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int len=q.size();
            vector<int> tmp;
            while(len--){
                auto x = q.front();
                q.pop();
                
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                
                tmp.push_back(x->val);
            }
            ans.push_back(tmp);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};