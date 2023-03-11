class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> prev=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<","<<j<<endl;
                board[i][j]=alive(prev,i,j)?1:0;
            }
        }
    }
    bool alive(vector<vector<int>>&b, int i, int j){
        vector<int> dirs[]={{1,1},{1,-1},{-1,1},{-1,-1},{0,-1},{0,1},{1,0},{-1,0}};
        int n=0;
        for(auto d:dirs){
            
            int ni = i+d[0];
            int nj = j+d[1];
            // cout<<ni<<","<<nj<<endl;
            if(ni>=0 && nj>=0 && ni<b.size() && nj<b[0].size() && b[ni][nj])
                n++;
        }
        // cout<<n<<endl;
        return ((b[i][j]==1&&n>1&&n<4)||(b[i][j]==0&&n==3));
    }
};