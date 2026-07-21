class Solution {
public:
    vector<vector<string>> result;
    
    void dfs(int row, vector<string>& board, unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag, int n){
        if(row==n){
            result.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(!cols.count(i) && !negDiag.count(row-i) && !posDiag.count(row+i)){
                cols.insert(i);
                negDiag.insert(row-i);
                posDiag.insert(row+i);

                board[row][i] = 'Q';
                dfs(row+1, board, cols, posDiag, negDiag, n);
                board[row][i] = '.';

                cols.erase(i);
                negDiag.erase(row-i);
                posDiag.erase(row+i);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;

        vector<string> board(n, string(n, '.'));
        dfs(0, board, cols, posDiag, negDiag, n);
        return result;
    }
};
