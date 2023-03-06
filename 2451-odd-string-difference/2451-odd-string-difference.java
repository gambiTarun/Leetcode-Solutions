class Solution {
    public String oddString(String[] words) {
        HashMap<List<Integer>,List<String>> mp = new HashMap();
        for(String s:words){
            List<Integer> curr = new ArrayList();
            for(int i=0;i<s.length()-1;i++){
                curr.add(s.charAt(i+1)-s.charAt(i));
            }
            if(mp.containsKey(curr)){
                mp.get(curr).add(s);
            }
            else{
                List<String> tmp = new ArrayList();
                tmp.add(s);
                mp.put(curr,tmp);
            }
        }
        
        for(List<String> v:mp.values())
        {
            if(v.size()==1)
                return v.get(0);
        }
        
        return "";
    }
}