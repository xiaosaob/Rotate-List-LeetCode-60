// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next) return head;
        ListNode *cur = head;
        int n = 1, i = 0;
        bool found = false;
        while(true) {
            if(found) {
                if(i == k) {
                    ListNode *next = cur->next;
                    cur->next = NULL;
                    return next;
                }
                cur = cur->next;
                ++i;
            } else {
                if(cur->next) {
                    ++n;
                    cur = cur->next;
                } else {
                    found = true;
                    cur->next = head;
                    k = n-k%n;
                }
            }
        }
    }
};
