class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9]= {0};

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                
                if(board[r][c]=='.') continue;
                int temp = board[r][c] ; //zero index
                int mask = 1 << temp;
                
                if(rows[r] & mask) return false;
                if(cols[c] & mask) return false;
                if(squares[3*(r/3)+c/3] & mask) return false;

                rows[r] |= mask;
                cols[c] |= mask;
                squares[3*(r/3)+c/3] |= mask;
            }
        }

        for(int i=0;i<9;i++){
            cout << rows[i]<<"\n";
        }
        return true;

    }
};
