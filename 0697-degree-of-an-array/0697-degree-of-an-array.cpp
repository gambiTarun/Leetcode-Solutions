class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int res=1,reslen=1;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]] = {1,i,i};
            else{
                mp[nums[i]][0]++;
                mp[nums[i]][2]=i;
            }
            int len=mp[nums[i]][2]-mp[nums[i]][1]+1;
            if(res<mp[nums[i]][0] || (res==mp[nums[i]][0] && reslen>len)){
                res = mp[nums[i]][0];
                reslen = len;
            }
            // cout<<res<<","<<reslen<<endl;
        }
        
        return reslen;
    }
};