class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    
    int findParent(int n){
        if(n==parent[n])
            return n;
        return findParent(parent[n]);
    }
    
    bool unionSet(int a, int b){
        int pa = findParent(a);
        int pb = findParent(b);
        
        if(pa==pb)
            return false;
        
        if(rank[pa]<rank[pb]){
            parent[pb] = pa;
        }
        else if(rank[pa]>rank[pb]){
            parent[pa]=pb;
        }
        else{
            parent[pa]=pb;
            rank[pb]++;
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        for(auto e:edges){
            if(!unionSet(e[0]-1,e[1]-1))
                return {e[0],e[1]};
        }
        
        return {};
    }
};