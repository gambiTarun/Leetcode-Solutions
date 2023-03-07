class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res=0,prev=-1;
        for(int i:timeSeries){
            if(i<=prev)
                res-=prev-i+1;
        
            res+=duration;
            prev=i+duration-1;
            
        }
        return res;
    }
}