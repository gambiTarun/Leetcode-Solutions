class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(*rbegin(days)+1,0);
        dp[0] = 0;
        set<int> dayss(days.begin(),days.end());
        for(int i=1;i<dp.size();i++){
            if(dayss.count(i))
                dp[i] = min(dp[max(0,i-1)]+costs[0],min(dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]));
            else
                dp[i] = dp[i-1];
        }
        
        return *rbegin(dp);
    }
};