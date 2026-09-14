#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SIZE 5
#define TABLE_SIZE 10

// 1. Arrays
void arrayExample() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Stack
typedef struct {
    int items[MAX];
    int top;
} Stack;

void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack* s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    printf("Stack underflow\n");
    return -1; // Stack underflow
}

void stackExample() {
    Stack s;
    s.top = -1;
    push(&s, 10);
    push(&s, 20);
    printf("Popped from stack: %d\n", pop(&s));
}

// 3. Queue
typedef struct {
    int items[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue* q, int value) {
    if ((q->rear + 1) % SIZE != q->front) {
        q->items[q->rear] = value;
        q->rear = (q->rear + 1) % SIZE;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue* q) {
    if (q->front != q->rear) {
        int item = q->items[q->front];
        q->front = (q->front + 1) % SIZE;
        return item;
    }
    printf("Queue underflow\n");
    return -1; // Queue underflow
}

void queueExample() {
    Queue q = { .front = 0, .rear = 0 };
    enqueue(&q, 1);
    enqueue(&q, 2);
    printf("Dequeued from queue: %d\n", dequeue(&q));
}

// 4. Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void linkedListExample() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = NULL;

    Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free allocated memory
    free(head->next);
    free(head);
}

// 5. Hash Table
typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry;

Entry* hashTable[TABLE_SIZE] = { NULL };

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
}

int search(int key) {
    int index = hash(key);
    Entry* entry = hashTable[index];
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1; // Key not found
}

void hashTableExample() {
    insert(1, 100);
    insert(11, 200); // Collision with key 1
    printf("Value for key 1: %d\n", search(1));
    printf("Value for key 11: %d\n", search(11));
}

// 6. Graph
typedef struct {
    int vertices;
    int** adjMatrix;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    g->adjMatrix = malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = calloc(vertices, sizeof(int));
    }
}

void addEdge(Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1; // For undirected graph
}

void graphExample() {
    Graph g;
    initGraph(&g, 3);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g.vertices; i++) {
        for (int j = 0; j < g.vertices; j++) {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < g.vertices; i++) {
        free(g.adjMatrix[i]);
    }
    free(g.adjMatrix);
}

// 7. Tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void treeExample() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal of Tree: ");
    inorder(root);
    printf("\n");

    // Free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
}

int main() {
    arrayExample();
    stackExample();
    queueExample();
    linkedListExample();
    hashTableExample();
    graphExample();
    treeExample();

    return 0;
}
