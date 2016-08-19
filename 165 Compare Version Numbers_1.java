// 165
// Compare Version Numbers
// https://leetcode.com//problems/compare-version-numbers/
public class Solution {
    public int compareVersion(String version1, String version2) {
        for(int i=0, l=0;;) {
            int j= version1.indexOf('.', i), m= version2.indexOf('.', l);
            int a = i<version1.length() ? Integer.parseInt(version1.substring(i, j>0?j:version1.length())) : 0;
            int b = l<version2.length() ? Integer.parseInt(version2.substring(l, m>0?m:version2.length())) : 0;
            if(a>b) return 1;
            else if(a<b) return -1;
            else {
            	if(j<0 && m< 0) return 0;
            	else {
            		i=j<0?version1.length():j+1;
            		l=m<0?version2.length():m+1;
            	}
            }
        }
    }
}