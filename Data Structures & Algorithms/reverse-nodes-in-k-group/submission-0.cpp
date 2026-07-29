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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while (temp!=NULL && count < k) {
            temp = temp -> next;
            count++;
        }

        if(count<k) return head;

        count = 0;


        while (curr!=NULL && count < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (forward!=NULL) {
            head -> next = reverseKGroup (forward , k);
        }
        return prev;
    }
};
