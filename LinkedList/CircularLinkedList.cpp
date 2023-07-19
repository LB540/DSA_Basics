#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node()
    {
        this->value = 0;
        next = NULL;
    }
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
    Node(int val, Node *next)
    {
        this->value = val;
        this->next = next;
    }
};

class CircularLL
{
public:
    Node *head;
    Node *tail;

    CircularLL()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    CircularLL(Node *head, Node *tail)
    {
        this->head = head;
        this->tail = tail;
    }

    void insert(int val)
    {
        Node *node = new Node(val);
        if (head == NULL)
        {
            head = node;
            tail = head;
            return;
        }
        tail->next = node;
        node->next = head;
        tail = tail->next;
    }

    void display()
    {
        Node *temp = head;
        if (head != NULL)
        {
            do
            {
                cout << temp->value << " --> ";
                temp = temp->next;
            } while (temp != head);
        }
        cout << " HEAD" << endl;
    }

    void deleteLL(int val)
    {
        if (head->value == val)
        {
            head = head->next;
            tail->next = head;
            return;
        }
        Node *temp = head;
        do
        {
            Node *n = temp->next;
            if (n->value == val)
            {
                temp->next = n->next;
                if (n->value == tail->value)
                {
                    tail = temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularLL lst;
    lst.insert(3);
    lst.insert(2);
    lst.insert(8);
    lst.insert(17);
    lst.insert(55);
    lst.display();
    lst.deleteLL(8);
    lst.display();
    return 0;
}