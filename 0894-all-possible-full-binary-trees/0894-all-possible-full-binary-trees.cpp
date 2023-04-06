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
        if(n%2==0)
            return {};
        unordered_map<int, vector<TreeNode*>> mp;
        mp[1].push_back(new TreeNode(0));
        int i=3;
        for(int i=3;i<=n;i++){
            int sum = i-1;
            int ln = 1; 
            int rn = i-2;
            while(ln<sum){
                for(auto l:mp[ln]){
                    for(auto r:mp[rn]){
                        TreeNode *n = new TreeNode(0,l,r);
                        mp[i].push_back(n);
                    }
                }
                ln+=2;
                rn-=2;
            }
        }
        
        return mp[n];
    }
};