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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        
        reverse(postorder.begin(),postorder.end());
        int ir=0;
        return helper(postorder,ir,inorder,0,inorder.size()-1,mp);
    }
    
    TreeNode* helper(vector<int> &postorder, int &ir, vector<int> &inorder, int s, int e, unordered_map<int,int> &mp){
        if(s>e)
            return nullptr;
        
        int split = postorder[ir++];
        TreeNode *right = helper(postorder,ir,inorder,mp[split]+1,e,mp);
        TreeNode *left = helper(postorder,ir,inorder,s,mp[split]-1,mp);
        
        return new TreeNode(split,left,right);
        
    }
};