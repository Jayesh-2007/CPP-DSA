// EVALUATE POSTFIX EXPRESSION
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b; // integer division
    case '^':
    {
        int res = 1;
        for (int i = 0; i < b; i++)
            res *= a;
        return res;
    }
    }
    return 0;
}

int evalPostfix(string postfix)
{
    stack<int> st;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int res = applyOp(num1, num2, c);
            st.push(res);
        }
    }
    return st.top();
}

int main()
{
    string postfix = "231*+9-"; // example: 2 + 3*1 - 9
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated Result: " << evalPostfix(postfix) << endl;
    return 0;
}