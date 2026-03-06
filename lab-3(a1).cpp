#include <bits/stdc++.h>
using namespace std;

#define MAX 200

class StackChar {
    char arr[MAX];
    int top;

public:
    StackChar() { top = -1; }

    void push(char x) {
        arr[++top] = x;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }

    void reset() {
        top = -1;
    }
};

class StackInt {
    int arr[MAX];
    int top;

public:
    StackInt() { top = -1; }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }

    void reset() {
        top = -1;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void reverseStr(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1]);
    }
}

void infixToPostfix(char infix[], char postfix[]) {

    StackChar stack;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[k++] = ch;
        }

        else if (ch == '(') {
            stack.push(ch);
        }

        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix[k++] = stack.pop();
            }
            stack.pop(); 
        }

        else { 
            while (!stack.isEmpty() &&
                   precedence(stack.peek()) >= precedence(ch)) {
                postfix[k++] = stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix[k++] = stack.pop();
    }

    postfix[k] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {

    char temp[MAX];
    strcpy(temp, infix);


    reverseStr(temp);

    for (int i = 0; temp[i]; i++) {
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }

    char postfix[MAX];
    infixToPostfix(temp, postfix);

    strcpy(prefix, postfix);
    reverseStr(prefix);
}

int applyOperator(int op1, int op2, char op) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
    }
    return 0;
}

int evaluatePrefix(char prefix[]) {

    StackInt stack;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {

        char ch = prefix[i];

        if (isdigit(ch)) {
            stack.push(ch - '0');
        }

        else {
            int op1 = stack.pop();
            int op2 = stack.pop();
            int result = applyOperator(op1, op2, ch);
            stack.push(result);
        }
    }

    return stack.pop();
}
int main() {

    char input[MAX];

    cout << "Enter full line: ";
    cin.getline(input, MAX);

    char expressions[20][MAX];
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++) {

        if (input[i] == '{') {

            int j = 0;
            i++;

            while (input[i] != '}' && input[i] != '\0') {
                expressions[count][j++] = input[i++];
            }

            expressions[count][j] = '\0';
            count++;
        }
    }

    cout << "\nTotal Expressions Found: " << count << endl;
    cout << "Corresponding Prefix Expressions:\n";

    int results[20];

    for (int i = 0; i < count; i++) {

        char prefix[MAX];
        infixToPrefix(expressions[i], prefix);

        cout << i + 1 << ". " << prefix << endl;

        results[i] = evaluatePrefix(prefix);
    }

    cout << "Result:\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << results[i] << endl;
    }

    return 0;
}