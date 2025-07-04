#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int f, r;
    int currSize, cap;

public:
    CircularQueue(int size)
    {
        cap = size;
        currSize = 0;
        arr = new int[cap];
        f = 0, r = -1;
    }

    void push(int val) // T.C = O(1)
    {
        if (currSize == cap)
        {
            cout << "CQ is full\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = val;
        currSize++;
    }

    void pop() // T.C = O(1)
    {
        if (empty())
        {
            cout << "CQ is empty\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front() // T.C = O(1)
    {
        if (empty())
        {
            cout << "CQ is empty\n";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }

    void printArray()
    {
        for (int i = 0; i < cap; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.printArray(); // 1 2 3
    cq.pop();        // 2 3
    cq.push(4);
    while (!cq.empty())
    {
        cout << cq.front() << " ";
        cq.pop();
    }

    return 0;
}
