class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> a[0]-b[0]);
        ArrayList<int[]> res = new ArrayList();
        for(int i=0;i<intervals.length;i++)
        {
            if(res.size()==0){
                res.add(intervals[i]);
                continue;
            }
            
            if(intervals[i][0]<=res.get(res.size()-1)[1])
                res.get(res.size()-1)[1] = Math.max(res.get(res.size()-1)[1],intervals[i][1]);
            else
                res.add(intervals[i]);
        }
        
        return res.toArray(new int[res.size()][]);
        
    }
}