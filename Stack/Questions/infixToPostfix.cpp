#include <iostream>
#include <stack>
using namespace std;

int precedance(char op) {
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    return 0;
}

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string infixToPostfix(string infix) {
    stack<int> st;
    string postfix = "";

    for(char c: infix) {
        if(isOperand(c)) {
            postfix += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove last '('
        } else { // operator
            while(!st.empty() && precedance(st.top()) >= precedance(c)) {
                if(c == '^' && st.top() == '^') break;
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }


    // pop reamining operations
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main (){
     string infix = "A+B*C-(D/E^F)*G";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}