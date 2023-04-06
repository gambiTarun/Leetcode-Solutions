class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        deque<pair<int,int>> dq;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                dq.emplace_back(i,0);
            if(board[i][n-1]=='O')
                dq.emplace_back(i,n-1);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')
                dq.emplace_back(0,i);
            if(board[m-1][i]=='O')
                dq.emplace_back(m-1,i);
        }
        
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        while(!dq.empty()){
            auto x = dq.front();
            dq.pop_front();
            
            board[x.first][x.second]='S';
            
            for(auto d: dirs){
                int r = x.first+d[0];
                int c = x.second+d[1];
                if(r>=0 && c>=0 && r<m && c<n && board[r][c]=='O'){
                    dq.emplace_back(r,c);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='S')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
    }
};