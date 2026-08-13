class LRUCache {
public:

    class Node {
    public:
        int key , val;
        Node* next;
        Node* prev;

        Node ( int k , int v ) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    Node* head = new Node (-1 , -1);
    Node* tail = new Node (-1 , -1);
    int limit;
    unordered_map <int , Node*> map;

    void addNode (Node* newNode) {
        Node* oldNext = head -> next;

        head -> next = newNode;
        oldNext -> prev = newNode;

        newNode -> next = oldNext;
        newNode -> prev = head;
    }

    void delNode (Node* oldNode) {

        Node* oldNext = oldNode -> next;
        Node* oldPrev = oldNode -> prev;

        oldPrev -> next = oldNext;
        oldNext -> prev = oldPrev;
    }


    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        Node* ansNode = map[key];
        int ans = ansNode -> val;

        delNode(ansNode);
        map.erase(key);

        addNode(ansNode);
        map[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* oldNode = map[key];
            delNode(oldNode);
            map.erase(key);
        }
        if (map.size() == limit) {
            map.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }
        Node* newNode = new Node (key , value);
        addNode(newNode);
        map[key] = newNode;
    }
};
