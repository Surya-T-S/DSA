#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// new node function
struct Node* createnode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert at the beginning  --> O(1)
void insertAtBeginning(struct Node** head,int data){
    struct Node* newNode = createnode(data);
    newNode->next = *head;
    *head = newNode;
}

// insert at the end  --> O(n)
void insertAtEnd(struct Node** head, int data){
    struct Node* newNode = createnode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;       // temp is used instead of the head as we need the head pointer always
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// insert at the specific position --> O(n)
void insertAtPosition(struct Node** head, int data, int position){
    if(position <= 1 || *head == NULL){
        insertAtBeginning(head,data);
        return;
    }
    struct Node* newNode = createnode(data);
    struct Node* temp = *head;

    for(int i=1; i<position-1 && temp->next != NULL; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete by value       --> O(n)
void deleteByValue(struct Node** head,int value){
    if(*head == NULL)   return;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;    // value not found

    prev->next = temp->next;
    free(temp);
}

// Delete by position   --> O(n)
void deleteByPosition(struct Node** head, int position){
    if(*head == NULL) return ;

    struct Node* temp = *head;

    if(position == 1){
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for(int i=1; i<position && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){     // position out of range 
        return ;
    }

    prev->next = temp->next ;
    free(temp);

}

// Search for an element  --> O(n)
int search(struct Node* head , int key){
    int pos = 1;
    while(head != NULL){
        if(head->data == key){
            return pos;
        }
        head = head->next;     // moving the head forward
        pos++;
    }
    return -1;    // not found
}

void display(struct Node* head){
    if(head == NULL){
        printf("Empty \n");
        return;
    }
    printf("Linked List: ");
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free the entire list  --> O(n)
void freeList(struct Node** head){
    struct Node* temp;
    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice,value,pos;

    while(1){
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Delete by Position\n");
        printf("6. Search Element\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insertAtBeginning(&head,value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                insertAtEnd(&head,value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d",&value,&pos);
                insertAtPosition(&head,value,pos);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head,value);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteByPosition(&head,pos);
                break;
            case 6:
                printf("Enter the value to search: ");
                scanf("%d",&value);
                pos = search(head,value);
                if (pos != -1)
                    printf("Element found at position %d\n", pos);
                else
                    printf("Element not found\n");
                break;
            case 7:
                display(head);
                break;
            case 8:
                freeList(&head);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice !\n");
        }

    }

    return 0;
}