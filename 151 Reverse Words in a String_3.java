// 151
// Reverse Words in a String
// https://leetcode.com//problems/reverse-words-in-a-string/
public class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i=s.length()-1,j=s.length();i>=0;--i) {
            if(s.charAt(i)==' ') j=i;
            else if(i==0 || s.charAt(i-1)==' '){
                if(sb.length()>0) sb.append(" ");
                sb.append(s.substring(i,j));
            }
        }
        return sb.toString();
    }
}