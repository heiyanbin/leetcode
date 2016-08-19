// 211
// Add and Search Word - Data structure design
// https://leetcode.com//problems/add-and-search-word-data-structure-design/
class WordDictionary {
private:
    struct TrieNode {
        bool wordEnd;
        TrieNode *next [26];
    };
    TrieNode *root;
    
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        insert(root, word, 0);
    }
    TrieNode * insert(TrieNode *x, string &word, int d) {
        if (x == NULL) x = new TrieNode();
        if (d == word.size()) x -> wordEnd = true;
        else 
            x -> next[word[d] - 'a'] = insert(x -> next[word[d] - 'a'], word, d + 1); 
        return x;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word, 0);
    }
    
    bool search(TrieNode * x, string &word, int d) {
        if (x == NULL) return false;
        if (d == word.size()) return x -> wordEnd;
        if (word[d] != '.')
            return search(x -> next[word[d] - 'a'], word, d + 1);
        else {
            for (int i = 0; i < 26; i++)
                if (search(x -> next[i], word, d + 1)) return true;
                
            return false;
        }
    }
    
    WordDictionary():root(new TrieNode()){}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");