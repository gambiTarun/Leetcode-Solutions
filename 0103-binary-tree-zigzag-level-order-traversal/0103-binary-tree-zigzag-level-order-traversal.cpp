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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> tmp;
            for(int i=0;i<s;i++){
                auto x = q.front();
                q.pop();
                
                if(!x)
                    continue;
                
                tmp.push_back(x->val);
                
                q.push(x->left);
                q.push(x->right);
                
            }
            if(lev%2)
                reverse(begin(tmp),end(tmp));
            if(!tmp.empty())
                res.push_back(tmp);
            lev++;          
        }
        return res;
    }
};