/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail (Node* &head , Node* &tail , int data) {
        Node* newNode = new Node (data);
        if (head == NULL || tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* copyHead = NULL;
        Node* copyTail = NULL;
        Node* temp = head;

        while (temp != NULL) {
            insertAtTail (copyHead , copyTail , temp->val);
            temp = temp -> next;
        }

        unordered_map <Node* , Node*> oldToNew;

        Node* originalNode = head;
        Node* copyNode = copyHead;

        while (originalNode != NULL) {
            oldToNew [originalNode] = copyNode;
            originalNode = originalNode -> next;
            copyNode = copyNode -> next;
        }

        originalNode = head;
        copyNode = copyHead;

        while (originalNode != NULL) {
            copyNode -> random = oldToNew [originalNode -> random];
            originalNode = originalNode -> next;
            copyNode = copyNode -> next;
        }
        return copyHead;
    }
};
