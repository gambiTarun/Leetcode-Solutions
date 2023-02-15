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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        q.push({root,0});
        while(!q.empty()){
            // int s = q.size();
            // while(s--){
            auto x = q.front();
            q.pop();

            if(x.first->left)
                q.emplace(x.first->left,x.second-1);
            if(x.first->right)
                q.emplace(x.first->right,x.second+1);

            mp[x.second].push_back(x.first->val);
            // }
            // i++;
        }
        
        for(auto i:mp)
            res.push_back(i.second);
        
        return res;
        
    }
};