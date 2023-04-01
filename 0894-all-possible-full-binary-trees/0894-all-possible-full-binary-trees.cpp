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
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> mp;
        
        mp[1] = {new TreeNode(0)};
        
        for(int i=3;i<=n;i+=2){
            int sum = i-1;
            int leftn = 1;
            int rightn = sum-1;
            while(leftn<sum){
                for(auto l: mp[leftn]){
                    for(auto r: mp[rightn]){
                        TreeNode *n = new TreeNode(0,l,r);
                        mp[i].push_back(n);
                    }
                }
                leftn+=2;
                rightn-=2;
            }
        }
        
        return mp[n];
    }
};