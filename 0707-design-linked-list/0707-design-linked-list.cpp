class MyLinkedList {
public:

    class Node{
    public:
        int val;
        Node* next;

        Node(int x){
            val = x;
            next = NULL;
        }
    };

    Node* dummy;
    int size;

    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index) {

        if(index < 0 || index >= size)
            return -1;

        Node* curr = dummy->next;

        while(index--){
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {

        Node* node = new Node(val);

        node->next = dummy->next;
        dummy->next = node;

        size++;
    }

    void addAtTail(int val) {

        Node* curr = dummy;

        while(curr->next){
            curr = curr->next;
        }

        curr->next = new Node(val);

        size++;
    }

    void addAtIndex(int index, int val) {

        if(index < 0 || index > size)
            return;

        Node* prev = dummy;

        while(index--){
            prev = prev->next;
        }

        Node* node = new Node(val);

        node->next = prev->next;
        prev->next = node;

        size++;
    }

    void deleteAtIndex(int index) {

        if(index < 0 || index >= size)
            return;

        Node* prev = dummy;

        while(index--){
            prev = prev->next;
        }

        Node* temp = prev->next;

        prev->next = temp->next;

        delete temp;

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */