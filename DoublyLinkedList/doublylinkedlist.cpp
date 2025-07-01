#include <iostream>
using namespace std;

class Node
{ // Node Structur each node have data, next pointer and previous pointer
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class doublyLinkedList
{
public:
    Node *head;
    Node *tail;
    doublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // adding element from head
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // adding element from tail
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // remove element from head of the doubly linked list
    void pop_front()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    // remove element from last of the doubly linked list
    void pop_back()
    {
        if (tail == NULL)
            return;
        Node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    // display doubly linkedlist element in forward direction
    void displayForward()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // display doubly linkedlist element in backward direction
    void displayBackward()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        while (temp != NULL)
        {
            cout << temp->data << "<->";
            temp = temp->prev;
        }
        cout << "NULL";
    }
};

int main()
{
    doublyLinkedList dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.pop_front();
    dll.pop_back();
    dll.displayForward();

    return 0;
}
