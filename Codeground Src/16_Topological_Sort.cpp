#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// typedef char bool;
#define MAX 55

typedef struct node {
    struct node* next;
    int value;
} node;

void add(node** head, int value) {
    node* new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    if (!(*head)) {
        new_node->next = NULL;
        (*head) = new_node;
    } else {
        new_node->next = (*head);
        (*head) = new_node;
    }
    return;
}

struct queue {
    int *data;
    int front, rear;
    int maxsize;
    int size;

};
void queue_init(struct queue* q, int sz) {
    q->maxsize = sz;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->data = (int*)malloc(q->maxsize * sizeof(int));
}
int queue_size(struct queue* q) {
    return q->size;
}
bool queue_empty(struct queue* q) {
    return queue_size(q) == 0;
}
bool queue_full(struct queue* q) {
    return q->size == q->maxsize;
}
void queue_push(struct queue* q, int val) {
    assert(!queue_full(q));
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->maxsize;
    q->size++;
}
void queue_pop(struct queue* q) {
    assert(!queue_empty(q));
    q->front = (q->front + 1) % q->maxsize;
    q->size--;
}
int queue_front(struct queue* q) {
    assert(!queue_empty(q));
    return q->data[q->front];
}
node *head[MAX];
int ind[MAX];
int N, M;
int u, v;
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        add(&head[u], v);
        ind[v]++;
    }
    struct queue q;
    queue_init(&q, MAX);
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) {
            queue_push(&q,i);
        }
    }
    while (!queue_empty(&q)) {
        int here = queue_front(&q);
        queue_pop(&q);
        printf("%d ", here);
        node* current_node = head[here];
        for (; current_node; current_node=current_node->next) {
            int there = current_node->value;
            ind[there]--;
            if (ind[there] == 0) {
                queue_push(&q,there);
            }
        }
    }
    return 0;
}