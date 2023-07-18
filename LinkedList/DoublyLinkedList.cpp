#include<iostream>
using namespace std;

class Node {
  public: 
    int value;
    Node* next;
    Node* prev;
    
    Node() {
        this->value = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int val) {
        this->value = val;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int val,Node* prev, Node* next) {
        this->value = val;
        this->prev = prev;
        this->next = next;
    }
};

class DLL {
  public:
    Node* head;
    // Node* tail; 
    DLL() {
        head = NULL;
    }
    
    void insertFirst(int val) {
        Node* node = new Node(val);
        // node->prev = NULL;
        if(head!=NULL) {
            head->prev = node;
            node->next = head;
        }    
        head = node;
    }
    
    void insertEnd(int val) {
        Node* node = new Node(val);
        if(head == NULL) {
            head = node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
    
    void display() {
        Node* temp = head;
        Node* tail;
        while(temp!=NULL) {
            cout << temp->value << " --> ";
            tail = temp;
            temp=temp->next;
        }
        cout << "END" << endl;
        
        cout << "Print in reverse: " << endl;
        while(tail!=NULL) {
            cout << tail->value << " --> ";
            tail = tail->prev;
        }
        cout << "END" << endl;
    }
    
    void insertAfter(int val, int after_val) {
        Node* node = new Node(after_val);
        Node* temp = head;
        while(temp!=NULL) {
            if(temp->value==val) {
                node->next = temp->next;
                temp->next = node;
                node->prev = temp;
                // return;
                break;
            }
            temp = temp->next;
        }
        if(node->next != NULL)
            node->next->prev = node;
        if(temp == NULL)
            cout << val << " is not found!" << endl;
    }
    
};

int main() {
    DLL lst;
    lst.insertFirst(3);
    lst.insertFirst(2);
    lst.insertFirst(8);
    lst.insertFirst(17);
    lst.insertEnd(55);
    lst.display();
    lst.insertAfter(55,121);
    cout << endl;
    lst.display();
    return 0;
}