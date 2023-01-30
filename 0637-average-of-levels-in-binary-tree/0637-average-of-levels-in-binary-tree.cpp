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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        long sum;
        while(!q.empty()){
            int len=q.size();
            sum=0;
            for(int i=0;i<len;i++){
                auto x=q.front();
                q.pop();
                
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                
                sum += x->val;
            }
            ans.push_back((double)sum/len);
        }
        
        return ans;
    }
};