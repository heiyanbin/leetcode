// 331
// Verify Preorder Serialization of a Binary Tree
// https://leetcode.com//problems/verify-preorder-serialization-of-a-binary-tree/
public class Solution {
    public boolean isValidSerialization(String preorder) {
        return help(preorder) && i >= preorder.length();
    }
    private boolean help(String preorder) {
        if (i >= preorder.length()) return false;
        int j = preorder.indexOf(',', i);
        if (j < 0) j = preorder.length();
        String val = preorder.substring(i, j);
        i = j + 1;
        if (val.equals("#")) return true;
        else return help(preorder) && help(preorder);
    }
    private int i = 0;
}