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

// Evaluate prefix expression (space separated, supports multidigit and ^)
int prefixEvaluation(char *exp) {
    int i;
    // Find the length of string
    for (i = 0; exp[i] != '\0'; i++);
    i--; // start from last character

    while (i >= 0) {
        if (exp[i] == ' ') {
            i--;
            continue;
        }

        // If digit, build full number (backwards!)
        if (isdigit(exp[i])) {
            int num = 0;
            int place = 1;

            // Read the full number (digits can be more than 1)
            while (i >= 0 && isdigit(exp[i])) {
                num = (exp[i] - '0') * place + num;
                place *= 10;
                i--;
            }
            push(num);
        }
        else { // Operator
            int v1 = pop();
            int v2 = pop();

            switch (exp[i]) {
                case '+': push(v1 + v2); break;
                case '-': push(v1 - v2); break;
                case '*': push(v1 * v2); break;
                case '/': push(v1 / v2); break;
                case '^': push((int)pow(v1, v2)); break;
            }
            i--;
        }
    }
    return pop();
}

int main() {
    // Example: + ^ 12 3 * 5 2  → equivalent to 12^3 + 5*2
    char expression[] = "+ ^ 12 3 * 5 2";

    printf("Result : %d\n", prefixEvaluation(expression));
    return 0;
}

