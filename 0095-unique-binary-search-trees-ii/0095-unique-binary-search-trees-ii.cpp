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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int s, int n){
        vector<TreeNode*> res;
        if(s>n){
            res.push_back(NULL);
            return res;
        }
        
        for(int i=s;i<=n;i++){
            vector<TreeNode*> left = helper(s,i-1);
            vector<TreeNode*> right = helper(i+1,n);

            for(auto l:left){
                for(auto r:right){
                    TreeNode* n = new TreeNode(i,l,r);
                    res.push_back(n);
                }
            }
        }
        // if(s+1==n)
        //     res.push_back(new TreeNode(n));
        // if(s==n)
        //     res.push_back(NULL);
        return res;
    }
};