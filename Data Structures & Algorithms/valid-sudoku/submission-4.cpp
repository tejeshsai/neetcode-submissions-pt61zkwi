class Solution {
public:
    bool isDuplicate(vector<char>& nums){
        unordered_set<char> seen;
        for(const char& n:nums){
            if(n!='.'){
                if(seen.count(n)==0){
                seen.insert(n);
                }
                else{
                cout << "here1";
                return true;
                }
            }

        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(isDuplicate(board[i])) return false;
            unordered_set<char> seen;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(seen.count(board[j][i])==0) seen.insert(board[j][i]);
                    else {
                        cout<< "here";
                        return false;}
                }
            }
        }
        int k=1;
        while(k<4){
            int j=1;
            while(j<4){
                unordered_set<char> seen;
                for(int i=(k-1)*3;i<3*k;i++){
                    for(int z=(j-1)*3;z<3*j;z++){
                        cout << i<<" "<<z;
                        if(board[i][z]!='.'){
                            
                            if(seen.count(board[i][z])==0) seen.insert(board[i][z]);
                            else {
                            cout<< "here";
                            return false;}
                        }
                    }
                }
                j++;
            }
            k++;
        
        }

        return true;
    }
};
