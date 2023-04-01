class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=m-1,mid,si=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[mid][0]<target && matrix[mid][n-1]<target)
                l=mid+1;
            else if(matrix[mid][0]>target && matrix[mid][n-1]>target)
                r=mid-1;
            else if(matrix[mid][0]<target && matrix[mid][n-1]>target)
                break;
            else
                return true;
        }
        
        si = mid;
        l=0,r=n-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[si][mid]<target)
                l=mid+1;
            else if(matrix[si][mid]>target)
                r=mid-1;
            else
                return true;
        }
        return false;
    }
};