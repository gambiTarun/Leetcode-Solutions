class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=nums[0],msum=nums[0];
        for(auto x:vector<int>(nums.begin()+1,nums.end())){
            csum = max(x,csum+x);
            msum = max(msum,csum);
        }
        return msum;
    }
};