// 212
// Word Search II
// https://leetcode.com//problems/word-search-ii/
public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<String>();
        if (board == null || words == null) return res;
        
        for (String word : words)
            trie.put(word, false);
        
        boolean[][] marked = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++)
            for (int j = 0; j < board[i].length; j++)
                dfs(board, marked, i, j, "", trie.root, res);
                
        return res;
    }
    void dfs(char[][] board, boolean[][] marked, int i, int j, String word, TrieNode root, List<String> res) {
        if (i < 0 || i == board.length || j < 0 || j == board[i].length || marked[i][j]
            || root.next[board[i][j] - 'a'] == null) return;
        
        marked[i][j] = true;
        if (Boolean.FALSE.equals(root.next[board[i][j] - 'a'].value)) {
            res.add(word + board[i][j]);
            root.next[board[i][j] - 'a'].value = true;
        }
        root = root.next[board[i][j] - 'a'];
        dfs(board, marked, i + 1, j, word + board[i][j], root, res);
        dfs(board, marked, i - 1, j, word + board[i][j], root, res);
        dfs(board, marked, i, j + 1, word + board[i][j], root, res);
        dfs(board, marked, i, j - 1, word + board[i][j], root, res);
        marked[i][j] = false;
    }
    private Trie<Boolean> trie = new Trie<Boolean>();
    private static class TrieNode {
            Object value = null;
            TrieNode[] next = new TrieNode[26];
        }
    private static class Trie<Value> {
        private TrieNode root = new TrieNode();
        public void put(String s, Value v) {
            put(root, s, 0, v);
        }
        public TrieNode put(TrieNode x, String s, int d, Value v) {
            if (x == null) x = new TrieNode();
            if (d == s.length()) {
                x.value = v;
                return x;
            }
            x.next[s.charAt(d) - 'a'] = put(x.next[s.charAt(d) - 'a'], s, d + 1, v);
            return x;
        }
        public Value get(String s) {
            return get(root, s, 0);
        }
        public Value get(TrieNode x, String s, int d) {
            if (x == null) return null;
            if (d == s.length()) return (Value)x.value;
            return get(x.next[s.charAt(d) - 'a'], s, d + 1);
        }
    }
    
    
}