class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto c:tasks)
            freq[c-'A']++;
        
        sort(freq.begin(),freq.end());
        
        int x = freq.size()-1;
        int maxfreq = freq[x--];
        int idles = (maxfreq-1)*n;
        
        while(x>=0 && idles>0)
            idles-=min(maxfreq-1,freq[x--]);
        
        idles = max(0,idles);
        
        return idles + tasks.size();
    }
};