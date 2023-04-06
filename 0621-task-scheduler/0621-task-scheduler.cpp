class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> frq;
        int maxfr = 0;
        char maxts = ' ';
        for(char c:tasks){
            frq[c] += 1;
            if(frq[c]>maxfr){
                maxfr = frq[c];
                maxts = c;
            }
        }
        
        int idle = (maxfr-1)*n;
        for(auto x:frq){
            if(x.first==maxts)
                continue;
            idle -= min(maxfr-1,x.second);
        }
        
        return max(0,idle)+tasks.size();
        
        
    }
};