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
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); ++i){
            if(cur->next[word[i] - 'a'] == NULL)
                cur->next[word[i] - 'a'] = new TrieNode();
            cur = cur->next[word[i] - 'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* res = find(word);
        return res && res->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix);
    }

private:
    TrieNode* root;
    TrieNode* find(const string &word){
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i){
            if(!cur->next[word[i] - 'a'])
                return NULL;
            cur = cur->next[word[i] - 'a'];
        }
        return cur;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
