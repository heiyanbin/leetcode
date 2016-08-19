// 307
// Range Sum Query - Mutable
// https://leetcode.com//problems/range-sum-query-mutable/
public class NumArray {

    public NumArray(int[] nums) {
        this.root = build(nums, 0, nums.length - 1);
    }

    public void update(int i, int val) {
        update(root, i, val);
    }
    private void update(TreeNode node, int i, int val) {
        if  (node.l == node.r) {
            node.v = val;
            return;
        }
        if (i <= (node.l + node.r) / 2) update(node.left, i, val);
        else update(node.right, i, val);
        node.v = node.left.v + node.right.v;
    }
    public int sumRange(int i, int j) {
       return sumRange(root, i, j);
    }
    private int sumRange(TreeNode node, int i, int j) {
        if (i == node.l && j == node.r) return node.v;
        int m = node.l + (node.r - node.l) / 2;
        if (i >= m + 1) return sumRange(node.right, i, j);
        if (j <= m ) return sumRange(node.left, i, j);
        return sumRange(node.left, i, m) + sumRange(node.right, m + 1, j);
    }
    private static class TreeNode {
        int l, r, v;
        TreeNode left, right;
        public TreeNode(int l, int r, int v) {
            this.l = l;
            this.r = r;
            this.v = v;
        }
    }
    private TreeNode build(int [] A, int l, int r) {
        if (l > r) return null;
        if (l == r) return new TreeNode(l, r, A[l]);
        int m = l + (r - l) / 2;
        TreeNode root = new TreeNode(l, r, 0);
        root.left = build(A, l, m);
        root.right = build(A, m + 1, r);
        root.v = root.left.v + root.right.v;
        return root;
    }
    private TreeNode root;
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);