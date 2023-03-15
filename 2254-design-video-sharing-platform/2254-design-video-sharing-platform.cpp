class VideoSharingPlatform {
public:
    unordered_map<int,string> vid;
    unordered_map<int,vector<int>> meta;
    priority_queue<int, vector<int>, greater<int>> usedID;
    VideoSharingPlatform() {
        usedID.push(0);
    }
    
    int upload(string video) {
        int id;
        id=usedID.top();
        usedID.pop();
        if(usedID.empty())
            usedID.push(vid.size()+1);
        
        vid[id] = video;
        meta[id] = {0,0,0};
        return id;
    }
    
    void remove(int videoId) {
        if(vid.find(videoId)==vid.end())
            return;
        usedID.push(videoId);
        vid.erase(videoId);
        meta.erase(videoId);
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if(vid.find(videoId)==vid.end())
            return "-1";
        
        if(startMinute<endMinute){
            meta[videoId][0]++;
            return vid[videoId].substr(max(0,startMinute), endMinute+1);
        }
            
        return "-1";
    }
    
    void like(int videoId) {
        if(vid.find(videoId)==vid.end())
            return;
        meta[videoId][1]++;
    }
    
    void dislike(int videoId) {
        if(vid.find(videoId)==vid.end())
            return;
        meta[videoId][2]++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if(vid.find(videoId)==vid.end())
            return {-1};
        return vector<int>(meta[videoId].begin()+1,meta[videoId].end());
    }
    
    int getViews(int videoId) {
        if(vid.find(videoId)==vid.end())
            return -1;
        return meta[videoId][0];
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */