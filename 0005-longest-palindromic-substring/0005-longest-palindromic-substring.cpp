class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        string res="";
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(i==j)
                    dp[i][j]=1;
                if(i+1==j && s[i]==s[j])
                    dp[i][j]=2;
                if(i<j && s[i]==s[j] && dp[i+1][j-1]!=0)
                    dp[i][j] = dp[i+1][j-1]+2;
                
                if(dp[i][j]>res.size())
                    res = s.substr(i,j-i+1);
            }
        }
        
        return res;
    }
};