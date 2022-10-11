class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n = price.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(maxAmount+1, vector<int>(maxCoupons+1,0)));
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=maxAmount;j++){
                for(int k=0;k<=maxCoupons;k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j-price[i-1]>=0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-price[i-1]][k]+tastiness[i-1]);
                    if(k>0 && j-int(price[i-1]/2)>=0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-int(price[i-1]/2)][k-1]+tastiness[i-1]);
                }
            }
        }
        
        return dp[n][maxAmount][maxCoupons];
    }
};