// 382
// Linked List Random Node
// https://leetcode.com//problems/linked-list-random-node/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode * sample = nullptr, *cur = head;
        
        for (int i = 0; cur; cur = cur->next, ++i) {
            int r = rand() % (i + 1);
            if (r == 0) sample = cur;
        }
        
        return sample->val;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */