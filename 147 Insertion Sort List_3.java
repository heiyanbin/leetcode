// 147
// Insertion Sort List
// https://leetcode.com//problems/insertion-sort-list/
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
    public ListNode insertionSortList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        ListNode p= head.next;
        ListNode prevP = head;
        while(p!=null)
        {
            ListNode i= head;
            ListNode prevI=null;
            while(p.val>=i.val && i!=p)
            {
                prevI=i;
                i=i.next;
            }
            if(i==p)
            {
                prevP=p;
                p=p.next;
            }
            else
            {
                prevP.next=p.next;
                p.next=i;
                if(prevI!=null)
                {
                    prevI.next=p;
                    prevI=prevI.next;
                }
                else
                {
                    head = p;
                }
                p=prevP.next;
            }
        }
        return head;
    }
}