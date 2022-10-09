class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<ans.size();j++){
                // cout<<ans[j]<<","<<strs[i][j]<<endl;
                if(ans[j]!=strs[i][j]){
                    ans.erase(ans.begin()+j,ans.end());
                    break;
                }
            }
        }
        return ans;
    }
};