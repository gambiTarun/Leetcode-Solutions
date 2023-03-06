class Solution {
    public int minimumRounds(int[] tasks) {
        HashMap<Integer,Integer> mp = new HashMap();
        for(int t:tasks)
            mp.put(t, mp.getOrDefault(t,0)+1);
        int res=0;
        for(int v:mp.values()){
            if(v==1)
                return -1;
            res+=v/3;
            if(v%3!=0)
                res++;
        }
        return res;
    }
}