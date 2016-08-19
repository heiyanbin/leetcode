// 306
// Additive Number
// https://leetcode.com//problems/additive-number/
public class Solution {
    public boolean isAdditiveNumber(String num) {
        dfs(num, 0, 0, 0, 0);
        return ans;
    }
    private void dfs(String num, int t, int i, long a, long b) {
        if (ans) return;
        if (t == num.length()) {
            if (i > 2) ans = true;
        }
        else {
            for (int k = t; k < num.length(); ++k) {
                if (num.charAt(t) == '0' && k > t) break;
                long v;
                try {
                    v = Long.parseLong(num.substring(t, k + 1));
                } catch (Exception e) {
                    break;
                }
                if (i < 2) dfs(num, k + 1, i + 1, b, v);
                else {
                    if (v < a + b) continue;
                    if (v == a + b) dfs(num, k + 1, i + 1, b, v);
                    else break;
                }
            }
        }
    }
    private boolean ans = false;
}