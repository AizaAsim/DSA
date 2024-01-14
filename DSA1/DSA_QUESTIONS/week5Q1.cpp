#include<iostream>
#include<string.h>
#include<cmath> 
using namespace std;

class stack {
    string postfix;
    int* s1;
    int length;
    int top;
    int oper1;
    int oper2;
    int r1;

public:
    stack() {
        cout << "Enter the postfix expression" << endl;
        cin >> postfix;
        length = postfix.length();
        s1 = new int[length];
        top = -1;
    }

    void push(int element) {
        if (top < length - 1) {
            top++;
            s1[top] = element;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    int pop() {
        if (top >= 0) {
            int temp = s1[top];
            top--;
            return temp;
        } else {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }

    int opr(int opr1, int opr2, char oper) {
        int result;
        switch (oper) {
            case '+':
                result = opr1 + opr2;
                return result;
                break;
            case '-':
                result = opr1 - opr2;
                return result;
                break;
            case '*':
                result = opr1 * opr2;
                return result;
                break;
            case '/':
                result = opr1 / opr2;
                return result;
                break;
            case '^':
               
            result = pow(opr1, opr2);  // Corrected order of operands
            return result;
            break;
        }
        return 0;
    }

    void evaluate() {
        int i = 0;
        while (postfix[i] != '\0') {
            if (postfix[i] >= '0' && postfix[i] <= '9') {
                int s2;
                s2 = postfix[i] - '0';
                this->push(s2);
            } else {
                oper2 = pop();
                oper1 = pop();
                r1 = opr(oper1, oper2, postfix[i]);
                push(r1);
            }
            i++;
        }
        cout << pop();
    }
};

int main() {
    stack s;
    s.evaluate();
    return 0;
}
