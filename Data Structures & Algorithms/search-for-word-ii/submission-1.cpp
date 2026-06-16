class TrieNode{
public:
    string word="";
    TrieNode* children[26];

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class Solution {
public:
    
    vector<string> result;
    TrieNode* root = new TrieNode();

    void insertWord(string word){
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a'] = new TrieNode();
            }
            curr = curr->children[ch-'a'];
        }
        curr->word = word;
    }

    void dfs(TrieNode* node, vector<vector<char>>& board, int r, int c){
        if(!node) return;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()) return;
        if(board[r][c]=='#') return;

        TrieNode* next = node->children[board[r][c]-'a'];
        if(next==nullptr) return;
        if(next->word!=""){
            result.push_back(next->word);
            next->word="";
        }

        char temp = board[r][c];
        board[r][c]='#';
        dfs(next, board, r+1, c);
        dfs(next, board, r-1,c);
        dfs(next, board, r, c+1);
        dfs(next, board, r, c-1);
        board[r][c] = temp;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) return {};
        for(string word:words){
            insertWord(word);
        }
        int rows = board.size();
        int cols = board[0].size();

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                dfs(root, board, r, c );
            }
        }
        return result;
    }
};
