class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int target=(nums1.size()+nums2.size())/2;
        int l=0, r=nums1.size()-1;

        while(true){
            
            int m1 = floor((l+r)/2.0);
            int m2 = target-m1-2;
            
            int left2 = (m2<0) ? INT_MIN : nums2[m2];
            int left1 = (m1<0) ? INT_MIN : nums1[m1];
            int right2= (m2+1>=nums2.size()) ? INT_MAX : nums2[m2+1];
            int right1= (m1+1>=nums1.size()) ? INT_MAX : nums1[m1+1];
            
            if(left1<=right2 && left2<=right1){
                if((nums1.size()+nums2.size())%2)
                    return std::min(right1,right2);
                else
                    return (std::max(left1,left2)+std::min(right1,right2))/2.0;
            }
            else if (left1>right2)
                r = m1-1;
            else
                l = m1+1;  
        }
    }
};