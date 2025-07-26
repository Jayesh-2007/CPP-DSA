#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> mainStack; // stores all element
    stack<int> minStack;  // stores minimum element

public:
    // push element into stack
    void push(int x)
    {
        mainStack.push(x);

        // if stack is empty or new element is <= current min, push to minStack
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }

    // remove top element
    void pop()
    {
        if (mainStack.empty())
            return;

        if (minStack.top() == mainStack.top())
        {
            minStack.pop();
        }

        mainStack.pop();
    }

    // return top element
    int top()
    {
        if (mainStack.empty())
        {
            cout << "Error: Stack is empty\n";
            return -1; // or throw an exception
        }
        return mainStack.top();
    }

    // return minimum element
    int getMin()
    {
        if (minStack.empty()) {
        cout << "Error: Stack is empty\n";
        return -1; // or throw an exception
    }
        return minStack.top();
    }
};

int main()
{
    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Minimum: " << s.getMin() << endl;               // Output: 2
    s.pop();                                                 // removes 2
    cout << "Minimum after popping: " << s.getMin() << endl; // Output: 3
    return 0;
}