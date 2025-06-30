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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insertion at end
    void insertionAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insertion at Beggining
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Delete Node
    void deleteNode(int val)
    {
        if (head == NULL)
            return;

        if (head->data == val)
        {
            Node *tempNode = head;
            head = head->next;
            delete tempNode;
            return;
        }

        Node *curr = head;
        while (curr->next != NULL && curr->next->data != val)
        {
            curr = curr->next;
        }

        if (curr->next == NULL)
            return; // value not found

        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    void displayList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.insertionAtEnd(3);
    ll.insertAtBeginning(2);
    ll.insertAtBeginning(1);
    ll.insertionAtEnd(7);
    ll.deleteNode(7);
    ll.displayList();
    return 0;
}
