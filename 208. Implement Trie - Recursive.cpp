class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        next.resize(26, NULL);
    }
    bool isWord;
    vector<TrieNode*> next;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        insert(root, 0, word);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *res = search(root, 0, word);
        return res != NULL && res->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *res = search(root, 0, prefix);
        return res != NULL;
    }

private:
    TrieNode* root;
    TrieNode* insert(TrieNode* root, int depth, const string &word){
        if(!root) root = new TrieNode();
        if(depth == word.length()){
            root->isWord = true;
            return root;
        }
        int c = word[depth++] - 'a';
        root->next[c] = insert(root->next[c], depth, word);
        return root;
    }
    TrieNode* search(TrieNode* root, int depth, const string &word){
        if(!root) return NULL;
        if(depth == word.length()) return root;
        int c = word[depth++] - 'a';
        return search(root->next[c], depth, word);
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
