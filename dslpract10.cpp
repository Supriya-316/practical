#include <iostream>
#include <string>
#include <cctype>
#include<cmath>
#include <stack>

using namespace std;


int precedence(char op){
    if (op =='*'|| op == '/'){
        return 2;
    }
    if (op=='+'|| op == '-'){
        return 1;
    }
        return 0;
}

int applyOperator(int a,int b,char op){
    switch(op){
        case '+' : return a + b ;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
        default  : return 0;
    }
}


string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch; 
        } 
        else if (ch == '(') {
            operators.push(ch);
        } 
        else if (ch == ')') {
            
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch); 
        }
    }

   
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            operands.push(ch - '0'); 
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            int result = applyOperator(a, b, ch);
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string infix, postfix;
    cout << "Enter the infix expression (single character operands and operators): ";
    cin >> infix;
    
    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    
    int result = evaluatePostfix(postfix);
    cout << "Result of postfix evaluation: " << result << endl;

    return 0;
}