//Here is the program to generate postfix from infix.
// Comments as instruction are included inside to explain every single code.
// But honestly the idea is from the professor's lide and the textbook page 164.
//
//Attention:
//- Only support operator : +, -, *, /, %;
//- Operand can only be : 'a' ~ 'z' and 'A' ~ 'Z';
//
//The source code is the file name 'main.cpp'. I use Intellij's C&C++ IDE Clion for coding,
// so there is one additional file call CMakeLists.
// It's for the IDE compiler only and I have also compiled this program under g++,
// the execute file is named InfixToPostfix under the same folder.
//
//Feel free to contact me if you have any question.
//
//Yifen Wu
//e-mail: anthonyeef@gmail.com


#include <iostream>
#include <stack>

using namespace std;

bool isLeftParenthesis(char token) {
    if (token == '(') {
        return true;
    } else
        return false;
}

bool isRightParenthesis(char token) {
    if (token == ')') {
        return true;
    } else
        return false;
}

bool isOperand(char token) {
    if(token <= 'z' && token >= 'a') {
        return true;
    } else
        if(token <= 'Z' && token >= 'A') {
            return true;
    } else
            return false;
}
int isPriority(char token) {
    int priority;
    if (token == '(')
        priority = 0;
    else if (token == '*' || token == '/' || token == '%')
        priority = 1;
    else if (token == '+' || token == '-')
        priority = 3;
    else if (token == '#')
        priority = 5;
    return priority;
}

int main() {
    string infix, postfix;
    int i = 0;
    char x;

//    Initialize the stack. Now the top == bottom == '#';
    stack<char> stack1;
    stack1.push('#');

    cout << "Please enter an expression:" << endl;
    cin >> infix;
    cout << "The original expression is:" << endl;
    cout << infix << endl;

    cout << "The postfix expression is:" << endl;

    for (i = 0; i < infix.length() ; i++) {
        x = infix[i];
        if(isOperand(x)) {
            postfix += x; // If it's operand, print;
        } else if(isRightParenthesis(x)) { // If it's ')', then clear the stack util '('; thus move '(' and ')' in the stack;
            while (!isLeftParenthesis(stack1.top())) {
                postfix += stack1.top();
                stack1.pop();
            }
            stack1.pop();
        }
        else if (isLeftParenthesis(stack1.top())) { // It it's '(', push it to the stack;
            stack1.push(x);
        }
        else {
            if(isPriority(stack1.top()) <= isPriority(x)){ // If it's not '(' but other operator, compare the priority with the stack top.
                postfix += stack1.top();
                stack1.pop();
            }
            stack1.push(x);
        }
    }


    while (!stack1.empty()) { // print the stack but not the '#';
        if (stack1.top()!= '#') {
            postfix += stack1.top();
        }
        stack1.pop();
    }

    cout << postfix << endl;
    return 0;
}