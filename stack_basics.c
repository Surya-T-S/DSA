#include <stdio.h>    // lab assignment 9
#define MAX 100

typedef struct{
    int stack[MAX];
    int top;
}stack;

//initializing function
void initialize(stack *s){
    s->top=-1;
}

//size function
int size(stack *s){
    return s->top+1;
}

//empty function
int isEmpty(stack *s){
    return s->top == -1;
}

//full function
int isFull(stack *s){
    return s->top == MAX-1;
}

//display function
void display(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

//push function
void push(stack *s, int value){
    // full or not
    if(isFull(s)){
        printf("The stack is full and element cannot be pushed");
        return;
    }

    //else push to stack
    else{
        s->stack[++(s->top)] = value;
    }
}

//pop function
int pop(stack *s){
    // empty checking
    if(isEmpty(s)){
        printf("Stack is empty and no element can be popped.");
        return -1;
    }

    //else push and return
    else{
        return s->stack[s->top--];
    }

}

int peek(stack *s){
    //empty or not checking 
    if(isEmpty(s)){
        printf("Stack is empty and no element can be popped.");
        return -1;
    }

    //else return the top most element
    else{
        return s->stack[s->top];
    }
}

//clear function
void clear(stack *s) {
    s->top = -1;
    printf("Stack cleared successfully!\n");
}

//search functionality
int search(stack *s, int value){
    for(int i=0; i<=s->top; i++){
        if(s->stack[i] == value){
            return i;  // return the position
        }
    }
    return -1;
}

//occurence function
int occurence(stack *s,int value){
    int count=0;
    for(int i=0;i<=s->top;i++){
        if(s->stack[i]==value){
            count++;
        }
    }
    return count;
}

//reverse the stack
void reversestack(stack *s){
    int temp;
    for(int i=0; i<(s->top+1)/2; i++){
        temp = s->stack[i];
        s->stack[i] = s->stack[s->top-i];
        s->stack[s->top-i] = temp;
    }
}

//sort the stack
void sortstack(stack *s){
    stack aux;
    aux.top = -1;
    while(!isEmpty(s)){
        int temp = pop(s);
        while(!isEmpty(&aux) && peek(&aux)>temp){
            push(s,pop(&aux));
        }
        push(&aux,temp);
    }
    while(!isEmpty(&aux)){
        push(s,pop(&aux));
    }
}
int main() {
    int op,value;
    stack s;
    initialize(&s);
    while(1){
        printf("Hello Welcome to Surya's Stack Kingdom\n");
        printf("\nStack Operations:\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display\n");
        printf("4) Peek\n");
        printf("5) Size\n");
        printf("6) Clear\n");
        printf("7) Search\n");
        printf("8) Count Occurrence\n");
        printf("9) Reverse Stack\n");
        printf("10) Sort Stack\n");
        printf("11) Exit\n");
        printf(":)");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d",&value);
            push(&s,value);
            break;
        case 2:
            printf("Popped: %d\n",pop(&s));
            break;
        case 3:
            display(&s);
            break;
        case 4:
            printf("The top element of stack is: %d\n",peek(&s));
            break;
        case 5:
            printf("The size of stack is: %d\n",size(&s));
            break;
        case 6:
            printf("Stack cleared\n");
            clear(&s);
            break;
        case 7:
            printf("Enter the element to be searched: ");
            scanf("%d",&value);
            if(search(&s,value)==-1){
                printf("Element not in the stack\n");
            }
            else{
                printf("Element found at %d\n",search(&s,value));
            }
            break;
        case 8:
            printf("Enter the element: ");
            scanf("%d",&value);
            printf("Number of occurences of the element is: %d\n",occurence(&s,value));
            break;
        case 9:
            printf("Stack reversed\n");
            reversestack(&s);
            break;
        case 10:
            printf("Stack sorted\n");
            sortstack(&s);
            break;
        case 11:
            return 0;
        default:
            printf("Entered wrong command");
            break;
        }
    }
    return 0;
}