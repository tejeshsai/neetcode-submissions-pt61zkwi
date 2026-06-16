class TrieNode{
public:
    TrieNode* children[26];
    bool isWord = false;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a'] = new TrieNode();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch:word){
            if(curr->children[ch-'a']==nullptr){
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch:prefix){
            if(curr->children[ch-'a']==nullptr){
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};
