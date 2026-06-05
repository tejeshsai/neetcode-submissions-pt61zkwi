class TrieNode{
    public:
        bool isWord = false;
        TrieNode* children[26];

        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
};

class Solution {
public:
    vector<string> globalRes;
    TrieNode* root = new TrieNode();
    void prepareTrie(vector<string>& words){
        TrieNode* curr = root;
        for(string& word : words){
            curr = root;
            for(char& ch: word){
                if(curr->children[ch-'a']==nullptr){
                    curr->children[ch-'a'] = new TrieNode();
                }
                curr = curr->children[ch-'a'];
            }
            curr->isWord = true;
        }
    }

    void dfs(TrieNode* node, vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited, string res){
        
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()) return;
        if(visited[r][c]) return;
        if(node->children[board[r][c]-'a']==nullptr) return;
        TrieNode* next = node->children[board[r][c]-'a'];
        res+=board[r][c];
        if(next->isWord){
            globalRes.push_back(res);
            next->isWord = false;
        }

        visited[r][c] = true;
        dfs(next, board, r-1, c, visited, res);
        dfs(next, board, r+1, c, visited, res);
        dfs(next, board, r, c+1, visited, res);
        dfs(next, board, r, c-1, visited, res);

        visited[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.empty()) return {};
        prepareTrie(words);
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                dfs(root, board, r, c, visited, "");
            }
        }

        return globalRes;
    }
};
