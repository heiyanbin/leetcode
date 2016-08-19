// 148
// Sort List
// https://leetcode.com//problems/sort-list/
class Solution {
    public ListNode sortList(ListNode head) {
        return  fastSort(head, null);
    }
    private ListNode fastSort(ListNode head, ListNode endExclusive)
    {
        if(head==endExclusive ||head.next==endExclusive) return head;
        ListNode dummy_left = new ListNode(-1), dummy_right=new ListNode(-1);
        dummy_right.next=head;
        ListNode cur_left=dummy_left, cur_right=head;
        for(ListNode p= head.next; p!=endExclusive;)
        {
           ListNode next = p.next;
           if(p.val<head.val)
           {
               cur_left.next=p;
               cur_left=p;
           }
           else if(p.val>head.val)
           {
               cur_right.next=p;
               cur_right=p;
           }
           else
           {
               p.next=dummy_right.next;
               dummy_right.next=p;
           }
           p=next;
        }
        cur_right.next=endExclusive;
        cur_left.next=dummy_right.next;
        head.next = fastSort(head.next, endExclusive);  
        return fastSort(dummy_left.next, cur_left.next);
    }
}