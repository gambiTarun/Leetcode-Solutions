class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(find(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
    
    bool find(int i, int j, vector<vector<char>> &b, string &w, int x){
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || x>w.size() || b[i][j]!=w[x]) return false;
        
        if(x==w.size()-1) return true;
        
        char c=b[i][j];
        b[i][j] = ' ';
        
        bool found = find(i+1,j,b,w,x+1) || find(i,j+1,b,w,x+1) || find(i-1,j,b,w,x+1) || find(i,j-1,b,w,x+1);
        
        b[i][j] = c;
        return found;
        
    }
};