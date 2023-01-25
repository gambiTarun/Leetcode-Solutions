class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(x==0 && y==0)
            return 0;
        
        if(abs(x)+abs(y)==2)
            return 2;
        
        vector<pair<int,int>> dirs = {{-1,-2},{-2,-1}};
        unordered_set<string> vis;
        queue<pair<int,int>> q;
        
        q.push({abs(x),abs(y)});
        int res=INT_MAX,steps=0;
        while(!q.empty()){
            
            int siz = q.size();
            steps++;
            while(siz--){
                
                pair<int,int> p = q.front();
                q.pop();
                
                for(auto d:dirs){
                    int ni = abs(p.first+d.first);
                    int nj = abs(p.second+d.second);
                    
                    if(ni==0&&nj==0)
                        res = min(res,steps);
                
                    if(abs(ni)+abs(nj)==2)
                        res = min(res,steps+2);
                    
                    string k = to_string(ni)+','+to_string(nj);
                    if(vis.find(k)==vis.end()){
                        q.push({ni,nj});
                        vis.insert(k);
                    }
                }
                // cout<<p.first<<","<<p.second<<endl;
                // cout<<steps<<endl;
                
            }
            
        }
        
        return res;
    }
};