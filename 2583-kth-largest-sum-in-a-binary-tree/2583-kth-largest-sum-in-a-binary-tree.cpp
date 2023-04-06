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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levsum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            long long sum=0;
            for(int i=0;i<s;i++){
                auto x = q.front();
                q.pop();
                
                if(!x)
                    continue;
                
                sum+=x->val;
                
                q.push(x->left);
                q.push(x->right);
            }
            if(sum>0)
                levsum.push_back(sum);
        }
        if(levsum.size()<k)
            return -1;
        sort(levsum.begin(),levsum.end(),greater<long long>());
        
        return levsum[k-1];
    }
};