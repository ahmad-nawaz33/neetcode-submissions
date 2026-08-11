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
private:
    ListNode* getMid (ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverse (ListNode* head) {

        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {

            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;

        }
    return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return;

        ListNode* middle = getMid (head);
        ListNode* second = middle -> next;
        middle -> next = NULL;

        second = reverse (second);

        ListNode* first = head;
        while (second != NULL) {

            ListNode* firstNext = first -> next;
            ListNode* secNext = second -> next;

            first -> next = second;
            second -> next = firstNext;

            first = firstNext;
            second = secNext;

        }
    }
};
