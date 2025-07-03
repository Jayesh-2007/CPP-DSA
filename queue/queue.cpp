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

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    // push element in queue
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (empty())
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // pop element in queue
    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            if (head == NULL)
            {
                tail == NULL;
            }
            delete temp;
        }
    }

    // return first value of queue
    int front()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    // print queue
    void display()
    {
        if (empty())
        {
            cout << "Queue is empty Nothing to display" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // check queue is empty or not
    bool empty()
    {
        return head == NULL;
    }

    ~Queue()
    {
        while (empty())
        {
            pop();
        }
    }
};

int main()
{
    Queue q;
    q.push(3);
    q.push(2);
    q.push(1);
    q.display();
    q.pop();
    q.display();
    cout << q.front() << endl;
    return 0;
}
