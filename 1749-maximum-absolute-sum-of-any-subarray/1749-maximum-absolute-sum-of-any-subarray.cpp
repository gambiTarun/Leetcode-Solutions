class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int cmax=nums[0],cmin=nums[0],smax=abs(nums[0]);
        for(auto x:vector<int>(nums.begin()+1,nums.end())){
            cmax = max(x,cmax+x);
            cmin = min(x,cmin+x);
            // cout<<cmax<<","<<cmin<<endl;
            smax = max(smax,max(cmax,abs(cmin)));
        }
        
        return smax;
    }
};