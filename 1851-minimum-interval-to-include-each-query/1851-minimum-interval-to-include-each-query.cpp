class Compare{
public:
    bool operator() (vector<int> a, vector<int> b)
    {
        // if(a[0]==b[0])
        //     return a[1]>b[1];
        return a[0]>b[0];
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> squers=queries, res;
        sort(squers.begin(),squers.end());
        sort(intervals.begin(),intervals.end());
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        unordered_map<int,int> mp;
        int i=0;
        for(int q:squers){
            while(i<intervals.size() && intervals[i][0]<=q){
                // cout<<q<<':'<<intervals[i][0]<<','<<intervals[i][1]<<endl;
                pq.push({intervals[i][1]-intervals[i][0]+1,intervals[i++][1]});
            }
            while(!pq.empty() && pq.top()[1]<q)
                pq.pop();
            // cout<<pq.top()[0]<<','<<pq.top()[1]<<endl;
            mp[q] = pq.empty()?-1:pq.top()[0];
        }
        for(int q:queries)
            res.push_back(mp[q]);
        
        return res;
    }
};