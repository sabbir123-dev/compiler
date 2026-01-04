
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int postfixevaluation(char *exp) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (possibly multidigit)
        if (isdigit(exp[i])) {
            int num = 0;

            // Build full number
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else {
            int v1 = pop();
            int v2 = pop();

            switch (exp[i]) {
                case '+': push(v2 + v1); break;
                case '-': push(v2 - v1); break;
                case '*': push(v2 * v1); break;
                case '/': push(v2 / v1); break;
                case '^': push((int)pow(v2, v1)); break; // v2 ^ v1
            }
            i++;
        }
    }
    return pop();
}

int main() {

    char expression[] = "12 3 4^*6/2+";

    printf("Result : %d", postfixevaluation(expression)+3);
    return 0;
}


