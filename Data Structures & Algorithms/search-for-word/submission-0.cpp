class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>& board, string& word, int index){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()) return false;
        if(board[r][c]=='#') return false;
        if(board[r][c]!=word[index]) return false;

        if(index == word.size()-1) return true;
        char temp = board[r][c];
        board[r][c]='#';
        bool top = dfs(r-1, c, board, word, index+1);
        bool bottom = dfs(r+1, c, board, word, index+1);
        bool left = dfs(r, c-1, board, word, index+1);
        bool right = dfs(r, c+1, board, word, index+1);
        board[r][c] = temp;
        return (left || right || top || bottom);
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(dfs(r, c, board, word, 0)) return true;
            }
        }
        return false;
    }
};
