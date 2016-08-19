// 208
// Implement Trie (Prefix Tree)
// https://leetcode.com//problems/implement-trie-prefix-tree/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
    bool wordEnd;
    TrieNode *next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        insert(root, s, 0);
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        auto x = search(root, key, 0);
        return x != nullptr && x -> wordEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto x = search(root, prefix, 0);
        return dfs(x);
    }

private:
    TrieNode* root;
    TrieNode* insert(TrieNode *x, string &s, int d) {
        if (x == nullptr) x = new TrieNode();
        if (d == s.size()) {
            x -> wordEnd = true;
            return x;
        }
        int index = s[d] - 'a';
        x -> next[index] = insert(x -> next[index], s, d + 1);
        return x;
    }
    TrieNode *search(TrieNode *x, string &s, int d) {
        if (x == nullptr) return nullptr;
        if (d == s.size()) return x;
        return search(x -> next[s[d] - 'a'], s, d + 1);
    }
    bool dfs(TrieNode *x) {
        if (x == nullptr) return false;
        if (x -> wordEnd == true) return true;
        for (int i = 0; i < 26; i++)
            if (dfs(x -> next[i])) return true;
            
        return false;
    }
    
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");