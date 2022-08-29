//https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:
    
    struct TrieNode{
        struct TrieNode* children[26];
        bool isLeaf=false;
    };
    
    TrieNode* root;
    
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* trie= root;
        for (int i=0; i<n; i++){
            int idx=word[i]-'a';
            if (trie->children[idx]==NULL){
                trie->children[idx]= new TrieNode();
            }
            trie=trie->children[idx];
        }
        trie->isLeaf=true;
    }
    
    bool search(string word) {
        int n=word.size();
        TrieNode* trie= root;
        for (int i=0; i<n; i++){
            int idx=word[i]-'a';
            if (trie->children[idx]==NULL){
                return false;
            }
            else{
                trie=trie->children[idx];
            }
        }
        return trie->isLeaf;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        TrieNode* trie= root;
        for (int i=0; i<n; i++){
            int idx=prefix[i]-'a';
            if (trie->children[idx]==NULL){
                return false;
            }
            else{
                trie=trie->children[idx];
            }
        }
        return true;
    }
};