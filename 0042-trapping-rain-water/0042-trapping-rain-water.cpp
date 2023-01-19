class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, leftM = height[0], n = height.size();
        vector<int> rightM(n,height[n-1]);
        for(int i=n-2;i>=0;i--){
            rightM[i] = max(rightM[i+1],(i==n-2?0:height[i+1]));
        }
        
        for(int i=1;i<n;i++){
            leftM = max((i==1?0:height[i-1]),leftM);
            // cout<<leftM<<","<<rightM[i]<<":"<<min(leftM,rightM[i])-height[i]<<endl;
            ans += min(leftM,rightM[i])<height[i]?0:min(leftM,rightM[i])-height[i];
        }
        
        return ans;
            
    }
};