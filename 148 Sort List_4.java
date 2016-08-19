// 148
// Sort List
// https://leetcode.com//problems/sort-list/
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        
        ListNode p= head, prevP= null,q= head;
        while(q!=null && q.next!=null)
        {
            prevP=p;
            p=p.next;
            q=q.next.next;
        }
        prevP.next=null;
        return mergeList(sortList(head), sortList(p));
        
    }

    ListNode mergeList(ListNode head1, ListNode head2)
    {
        if(head1==null) return head2;
        if(head2==null) return head1;
        ListNode head, p;
        if(head1.val<=head2.val)
        {   
            head=head1;
            head1=head1.next;
        }
        else
        {
            head=head2;
            head2=head2.next;
        }
        p = head;
        while(head1!=null && head2!=null)
        {
            if(head1.val<=head2.val)
            {    
                p.next=head1;
                head1=head1.next;
            }
            else
            {
                p.next=head2;
                head2=head2.next;
            }
            p=p.next;
        }
        if(head1==null)
        {
            p.next=head2;
        }
        else
            p.next=head1;
            
        return head;
    }
    
}