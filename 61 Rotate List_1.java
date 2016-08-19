// 61
// Rotate List
// https://leetcode.com//problems/rotate-list/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int n) {
		if (head == null || n < 1) return head;
        ListNode p = head;
        int len = 1;
        for (; p.next != null; ++len, p = p.next) ;
        n = len - n % len;
        p.next = head;
        for (int i = 0; i < n; p = p.next, ++i) ;
        head = p.next;
        p.next = null;
        return head;
    }
}