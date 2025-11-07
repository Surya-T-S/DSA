#include <stdio.h>

#define MAX 100  // maximum number of vertices

int queue[MAX];   // to store the BFS queue
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if (rear == MAX - 1)
        return;  // Queue overflow
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1; // Queue empty
    return queue[front++];
}

// // BFS function
// void bfs(int adj[MAX][MAX], int visited[MAX], int n, int start) {
//     enqueue(start);
//     visited[start] = 1;

//     printf("BFS Traversal starting from vertex %d: ", start);

//     while (front <= rear) {
//         int node = dequeue();
//         printf("%d ", node);

//         // Visit all adjacent unvisited vertices
//         for (int i = 0; i < n; i++) {
//             if (adj[node][i] == 1 && !visited[i]) {
//                 enqueue(i);
//                 visited[i] = 1;
//             }
//         }
//     }
// }

void bfs(int adj[MAX][MAX],int visited[MAX],int n,int start){
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ",start);
    while(front <= rear){
        int node = dequeue();
        printf("%d ",node);

        //Visit all adjacent unvisited vertices
        for(int i=0; i<n; i++){
            if(adj[node][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }

        }
    }
}

int main() {
    int n; // number of vertices
    int adj[MAX][MAX]; // adjacency matrix
    int visited[MAX] = {0};
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(adj, visited, n, start);

    return 0;
}
