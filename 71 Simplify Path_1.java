// 71
// Simplify Path
// https://leetcode.com//problems/simplify-path/
public class Solution {
   public String simplifyPath(String path) {
        if(path==null || path.isEmpty() ) return path;
        String[] parts = path.trim().split("/+");
        List<String> s = new ArrayList<String>();
        for(String part : parts)
        {
        	if(!part.equals(".") && !part.equals(".."))
        		s.add(part);
        	else if(part.equals("..") && !s.isEmpty())
        		s.remove(s.size()-1);
        }
        if(s.isEmpty()) return "/";
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.size();i++)
        {
        	if(sb.length()==0 || sb.charAt(sb.length()-1)!='/') sb.append("/");
        	sb.append(s.get(i));
        }
       return sb.toString();
    }
}