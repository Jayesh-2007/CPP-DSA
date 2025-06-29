//Stack Implementation
#include <iostream>
using namespace std;
#include <vector>

class Stack
{
    vector<int> vec;

public:
    void push(int val)
    {
        vec.push_back(val);
    }
    void pop()
    {
        vec.pop_back();
    }
    int top()
    {
        return vec[vec.size() - 1];
    }
    bool empty()
    {
        return vec.size() == 0;
    }
};

int main()
{
    // stack -> LIFO (Last in First Out Ds)
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    return 0;
}

// output:-
//   1
//   2
//   3
//   space
