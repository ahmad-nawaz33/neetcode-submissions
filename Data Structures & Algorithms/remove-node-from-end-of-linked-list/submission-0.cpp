/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i=0; i<n; i++) {
            fast = fast -> next;
        }

        if (fast == NULL) {
            head = head -> next;
            return head;
        }

        while (fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode* del = slow -> next;
        slow -> next = del -> next;
        delete (del);

        return head;
    }
};
