#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100 // Maximum capacity of the heap

struct Customer {
    char name[50];
    int priority; // 1 = Highest, 4 = Lowest
};

struct PriorityQueue {
    struct Customer heap[MAX_CUSTOMERS];
    int size;
};

// Returns the index of the parent node
int parent(int i) { return (i - 1) / 2; }

// Returns the index of the left child
int left_child(int i) { return (2 * i) + 1; }

// Returns the index of the right child
int right_child(int i) { return (2 * i) + 2; }

// Swaps two Customer structs in the heap array
void swap(struct Customer* a, struct Customer* b) {
    struct Customer temp = *a;
    *a = *b;
    *b = temp;
}

// Map category choice to priority
int getPriorityFromCategory(int choice) {
    switch (choice) {
        case 1: return 1; // Differently Abled (Highest Priority)
        case 2: return 2; // Senior Citizen
        case 3: return 3; // Defence Personnel
        case 4: return 4; // Ordinary Person (Lowest Priority)
        default: return 4;
    }
}

void heapify_up(struct PriorityQueue* pq, int i) {
    // Stop if we are at the root or the parent has a smaller priority (Min-Heap property satisfied)
    if (i > 0 && pq->heap[parent(i)].priority > pq->heap[i].priority) {
        swap(&pq->heap[i], &pq->heap[parent(i)]);
        heapify_up(pq, parent(i)); // Recurse up
    }
}

void heapify_down(struct PriorityQueue* pq, int i) {
    int smallest = i;
    int l = left_child(i);
    int r = right_child(i);

    // Find the smallest among the node, left child, and right child
    if (l < pq->size && pq->heap[l].priority < pq->heap[smallest].priority)
        smallest = l;

    if (r < pq->size && pq->heap[r].priority < pq->heap[smallest].priority)
        smallest = r;

    // If the smallest is not the current node, swap and continue heapifying down
    if (smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapify_down(pq, smallest);
    }
}

void enqueue(struct PriorityQueue* pq, char* name, int priority) {
    if (pq->size >= MAX_CUSTOMERS) {
        printf("Queue is full. Cannot add '%s'.\n", name);
        return;
    }

    // Insert the new customer at the end
    strcpy(pq->heap[pq->size].name, name);
    pq->heap[pq->size].priority = priority;
    pq->size++;

    // Restore the Min-Heap property by 'bubbling up'
    heapify_up(pq, pq->size - 1);

    printf("Customer '%s' added to queue with priority %d.\n", name, priority);
}

void dequeue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty. No customer to serve.\n");
        return;
    }

    // The customer with the highest priority is always at the root (index 0)
    struct Customer served = pq->heap[0];

    // Move the last element to the root
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    // Restore the Min-Heap property by 'bubbling down'
    heapify_down(pq, 0);

    printf("Serving Customer: %s (Priority: %d)\n", served.name, served.priority);
}

void display(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue (Heap Array Order - NOT necessarily sorted):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Index %d | Name: %s | Priority: %d\n", i, pq->heap[i].name, pq->heap[i].priority);
    }
}

int main() {
    struct PriorityQueue pq = { .size = 0 }; // Initialize size to 0

    int choice;
    char name[50];
    int catChoice;
    int priority;

    while (1) {
        printf("\n====== Priority Queue Menu (Min-Heap) ======\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue (Heap Order)\n");
        printf("0. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input
            while(getchar() != '\n'); // Clear buffer
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                if (fgets(name, sizeof(name), stdin) == NULL) continue;
                name[strcspn(name, "\n")] = '\0'; // remove newline

                printf("Select Category:\n");
                printf("1. Differently Abled\n");
                printf("2. Senior Citizen\n");
                printf("3. Defence Personnel\n");
                printf("4. Ordinary Person\n");
                printf("Enter choice: ");
                if (scanf("%d", &catChoice) != 1) {
                    while(getchar() != '\n');
                    printf("Invalid input. Category not added.\n");
                    continue;
                }
                getchar();

                priority = getPriorityFromCategory(catChoice);
                enqueue(&pq, name, priority);
                break;

            case 2:
                dequeue(&pq);
                break;

            case 3:
                display(&pq);
                break;

            case 0:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}