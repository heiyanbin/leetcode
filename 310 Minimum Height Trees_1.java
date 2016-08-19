// 310
// Minimum Height Trees
// https://leetcode.com//problems/minimum-height-trees/
public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<Integer>();
        if (n < 1) return ans;
        adj = (List<Integer>[]) new List[n];
        for (int i = 0; i < n; ++i)
            adj[i] = new ArrayList<Integer>();

        for (int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() <= 1) q.offer(i);
        }
        
        for (; n > 2; ) {
            for (int i = 0, sz = q.size(); i < sz; --n, ++i) {
                Integer leaf = q.poll();
                int other = adj[leaf].get(0);
                adj[other].remove(leaf);
                if (adj[other].size() == 1) q.offer(other);
            }
        }
        for (; q.size() > 0; ) ans.add(q.poll());
        return ans;
    }
    private List<Integer>[] adj;
}