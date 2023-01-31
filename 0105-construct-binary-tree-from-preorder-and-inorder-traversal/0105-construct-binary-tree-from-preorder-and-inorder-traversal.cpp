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
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int ir=0;
        return arrtoTree(preorder,inorder,ir,0,inorder.size()-1,mp);
    }
    
    TreeNode* arrtoTree(vector<int>& preorder, vector<int>& inorder, int &iroot, int l, int r, unordered_map<int,int> &mp){
        if(l>r)
            return NULL;
        int pivot = mp[preorder[iroot++]];
        
        TreeNode *node = new TreeNode(inorder[pivot]);
        
        node->left = arrtoTree(preorder,inorder,iroot,l,pivot-1,mp);
        node->right = arrtoTree(preorder,inorder,iroot,pivot+1,r,mp);
        return node;
    }
};