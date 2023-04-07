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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        int ir=0;
        return helper(preorder,ir,inorder,0,inorder.size()-1,mp);
    }
    
    TreeNode *helper(vector<int>& preorder, int &p, vector<int>& inorder, int s, int e, unordered_map<int,int> &mp){
        if(s>e)
            return nullptr;
        
        int split = preorder[p++];
        // cout<<split<<endl;
        TreeNode *left = helper(preorder,p,inorder,s,mp[split]-1,mp);
        TreeNode *right = helper(preorder,p,inorder,mp[split]+1,e,mp);
        
        return new TreeNode(split,left,right);
    }
};