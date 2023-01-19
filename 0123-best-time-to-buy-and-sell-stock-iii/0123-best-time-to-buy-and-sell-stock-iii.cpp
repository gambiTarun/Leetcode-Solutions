class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),currmin=prices[0],currmax=prices[n-1],res=INT_MIN;
        vector<int> l(n,0), r(n+1,0);
        l[0]=r[0]=0;
        for(int i=1;i<n;i++){
            currmin = min(currmin,prices[i]);
            l[i] = max(l[i-1],prices[i]-currmin);
        }
        for(int i=n-2;i>=0;i--){
            currmax = max(currmax,prices[i]);
            r[i] = max(r[i+1],currmax-prices[i]);
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<l[i]<<",";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<r[i]<<",";
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            res = max(res,l[i]+r[i+1]);
        }
        return res;
    }
};