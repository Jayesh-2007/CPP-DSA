#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList
{
    Node *head;
    Node *tail;

public:
    CircularLinkedList()
    {
        head = tail = NULL;
    }

    // insert node at head of the circular linked list
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        { // when circular list not have any element
            head = tail = newNode;
            tail->next = head; // condition for circular linked list
        }
        else
        { // element occurs in curcular list
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    // insert node at tail of the circular linked list
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // delete Node at head of the circular linked list
    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    // delete Node at tail of the circular linked list
    void deleteAtTail()
    {
        if (head == NULL)
            return;
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = tail;
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList()
    {
        while (head != NULL)
        {
            deleteAtHead();
        }
    }
};

int main()
{
    CircularLinkedList cll;

    cll.insertAtTail(10);
    cll.insertAtTail(20);
    cll.insertAtHead(5);

    cll.display(); // Expected: 5 10 20

    cll.deleteAtHead();
    cll.display(); // Expected: 10 20

    cll.deleteAtTail();
    cll.display(); // Expected: 10

    return 0;
}
