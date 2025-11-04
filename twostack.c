// Implements two stacks in a single array and provides stack operations for both.
#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} twostack;

// Initialize both stacks
void initialize(twostack *s) {
    s->top1 = -1;
    s->top2 = MAX;
}

// Push stack 1
void push1(twostack *s, int x) {
    if (s->top1 + 1 == s->top2) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top1)] = x;
}

// Push stack 2
void push2(twostack *s, int x) {
    if (s->top1 + 1 == s->top2) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[--(s->top2)] = x;
}

// Pop stack 1
int pop1(twostack *s) {
    if (s->top1 == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top1)--];
}

// Pop stack 2
int pop2(twostack *s) {
    if (s->top2 == MAX) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top2)++];
}

// Peek stack 1
void peek1(twostack *s) {
    if (s->top1 == -1) {
        printf("Stack 1 is empty\n");
        return;
    }
    printf("Top element of stack 1: %d\n", s->arr[s->top1]);
}

// Peek stack 2
void peek2(twostack *s) {
    if (s->top2 == MAX) {
        printf("Stack 2 is empty\n");
        return;
    }
    printf("Top element of stack 2: %d\n", s->arr[s->top2]);
}

int main() {
    twostack s;
    int choice, value;
    initialize(&s);

    while (1) {
        printf("\n1. Push stack1\n2. Push stack2\n3. Pop stack1\n4. Pop stack2\n5. Peek stack1\n6. Peek stack2\n7. Exit\n-> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                push1(&s, value);
                break;

            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                push2(&s, value);
                break;

            case 3:
                value = pop1(&s);
                if (value != -1)
                    printf("Popped from stack1: %d\n", value);
                break;

            case 4:
                value = pop2(&s);
                if (value != -1)
                    printf("Popped from stack2: %d\n", value);
                break;

            case 5:
                peek1(&s);
                break;

            case 6:
                peek2(&s);
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}