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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int s = q.size();
            int last=-1;
            for(int i=0;i<s;i++){
                auto x = q.front();
                q.pop();
                
                if(!x)
                    continue;
                last = x->val;
                
                q.push(x->left);
                q.push(x->right);
            }
            if(!q.empty())
                res.push_back(last);
        }
        return res;
    }
};