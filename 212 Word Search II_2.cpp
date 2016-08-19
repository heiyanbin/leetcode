// 212
// Word Search II
// https://leetcode.com//problems/word-search-ii/
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto w : words) trie.put(w, 1);
        vector<string> res;
        vector<vector<bool>> marked(board.size(), vector<bool>(board[0].size(), false));
        string word = "";
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                dfs(board, marked, i, j, word, trie.root, res);
        
        return res;
    }
private:
    struct TrieNode {
        int value;
        TrieNode *next[26];
        TrieNode():value(0) {fill(next, next + 26, nullptr);}
    };
    class Trie {
    public:
        TrieNode *root;
        Trie():root(new TrieNode) {}
        void put(string &key, int value) {
            put(root, key, 0, value);
        }
    private:
        TrieNode* put(TrieNode* x, string &key, int d, int value) {
            if (x == nullptr) x = new TrieNode;
            if (d == key.size()) {
                x -> value = value;
                return x;
            }
            x -> next[key[d] - 'a'] = put(x -> next[key[d] - 'a'], key, d + 1, value);
            return x;
        }
    };
    Trie trie;
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &marked, int i, int j, string &word, TrieNode* root, vector<string> &res ) {
        if (i<0 || i==board.size() || j < 0 || j == board[i].size() || marked[i][j] || !root->next[board[i][j] - 'a'])
            return;
        marked[i][j] = true;
        word.push_back(board[i][j]);
        if (root -> next[board[i][j] - 'a'] -> value == 1) {
            res.push_back(word);
            root -> next[board[i][j] - 'a'] -> value = 2;
        }
        root = root -> next[board[i][j] - 'a'];
        dfs(board, marked, i + 1, j, word, root, res);
        dfs(board, marked, i - 1, j, word, root, res);
        dfs(board, marked, i, j + 1, word, root, res);
        dfs(board, marked, i, j - 1, word, root, res);
        word.pop_back();
        marked[i][j] = false;
    }
};