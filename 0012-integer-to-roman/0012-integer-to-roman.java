class Solution {
    private static int[] vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    private static String[] sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    public String intToRoman(int num) {
        StringBuilder s = new StringBuilder();
        for(int i=0;i<vals.length && num>0;i++){
            while(vals[i]<=num){
                num-=vals[i];
                s.append(sym[i]);
            }
        }
        return s.toString();
    }
}