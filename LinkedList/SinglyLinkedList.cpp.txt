// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
    
    public:
        Node() {
            this->val = 0;
            next = NULL;
        }
        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
        Node(int val, Node* next) {
            this->val = val;
            this->next = next;
        }
};

class LinkedList {
    public:
        int size;
        Node* head;
        Node* tail;
    public:
        LinkedList() {
            this->size = 0; 
            head = NULL;
            tail = NULL;
        }
        
        void insertFirst(int val) {
            Node* node = new Node(val);
            node->next = head;
            head = node;
            if(tail == NULL) {
                tail = node;
            }
            size += 1;
        }
        
        void insertEnd(int val) {
            Node* node = new Node(val);
            // Node* temp = head;
            // while(temp->next!=NULL) {
            //     temp = temp->next;
            // }
            // temp->next = node;
            if(tail==NULL) {
                insertFirst(val);
                return;
            }
            tail->next = node;
            tail = tail->next;
            size+=1;
        }
        
        void insertAtInd(int val, int ind) {
            if(ind==0) {
                insertFirst(val);
                return;
            }else if(ind == size) {
                insertEnd(val);
                return;
            }
            Node* node = new Node(val);
            Node* temp = head;
            while(ind>1) {
                temp = temp->next;
                ind--;
            }
            node->next = temp->next;
            temp->next = node;
            size+=1;
        }
        
        int deleteFirst() { 
            int val = head->val;
            head= head->next;
            if(head==NULL) {
                tail = head;
            }
            size-=1;
            return val;
        }
        
        int deleteEnd() {
            int val = tail->val;
            if(size<=1) {
                return deleteFirst();
            }
            Node* temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
            size-=1;
            return val;
        }
        
        int deleteAtInd(int ind) {
            if(ind == 0) {
                return deleteFirst();
            }else if(ind == size) {
                return deleteEnd();
            }
            Node* temp = head;
            while(ind>1) {
                temp = temp->next;
                ind--;
            }
            int val = temp->next->val;
            temp->next = temp->next->next;
            size-=1;
            return val;
        }
        
        void displayLL() {
            Node* temp = head;
            while(temp!=NULL) {
                cout << temp->val << " --> ";
                temp = temp->next;
            }
            cout << "END" <<endl;
        }
};

int main() {
    // Write C++ code here
    LinkedList lst;
    lst.insertFirst(1);
    lst.insertFirst(2);
    lst.insertFirst(3);
    lst.insertFirst(4);
    lst.insertEnd(10);
    lst.insertAtInd(100,3);
    // cout << lst.size << endl;
    lst.displayLL();
    cout << lst.deleteFirst() << " deleted!" << endl;
    lst.displayLL();
    cout << lst.deleteEnd() << endl;
    lst.displayLL();
    cout << lst.deleteAtInd(2) << endl;
    lst.displayLL();
    return 0;
}