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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        int lev=0;
        
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto n = q.front();
                q.pop();
                
                if(!n)
                    continue;
                
                q.push(n->left);
                q.push(n->right);
                
                if(res.size()==lev)
                    res.push_back({n->val});
                else
                    res[lev].push_back(n->val);
                
            }
            lev++;
        }
        
        return res;
    }
};