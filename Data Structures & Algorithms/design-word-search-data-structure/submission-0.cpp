class TrieNode{
public:
    TrieNode* children[26];
    bool isWord = false;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a'] = new TrieNode();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isWord = true;
    }
    
    bool dfs(TrieNode* node, int index, string& word){
        if(index == word.size()) return node->isWord;
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]!=nullptr){
                    if(dfs(node->children[i],index+1, word)) return true;
                }
            }
            return false;
        }else{
            TrieNode* next = node->children[word[index]-'a'];
            if(next == nullptr) return false;
            else return dfs(next, index+1, word);

        }
    }
    bool search(string word) {
        if(word=="") return false;
        return dfs(root, 0, word);
    }
};
