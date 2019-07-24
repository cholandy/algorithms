#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
    int size;
};

void queue_init(struct queue *q) {
    q->size = 0;
    q->front= NULL;
    q->rear = NULL;
}
void queue_push(struct queue *q, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->value = val;
    q->size++;
    if (q->front == NULL && q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void queue_pop(struct queue *q) {
    if (q->front->next == NULL) {
        q->front = q->rear = NULL;
        q->size--;
    } else if(q->front->next!=NULL) {
        struct node* removeNode = q->front;
        q->front = q->front->next;
        q->size--;
        free(removeNode);
    }
}
int queue_front(struct queue *q) {
    return q->front->value;
}
int edge[1010][1010];
int visited[1010];
int N, M;
int u, v;

void bfs(int cur) {
    struct queue q;
    queue_init(&q);
    visited[cur] = 1;
    queue_push(&q, cur);
    while (q.size) {
        int here = queue_front(&q);
        queue_pop(&q);
        printf("%d ", here);
        for (int there = 1; there <= N; there++) {
            if (visited[there] || (edge[here][there]==0)) continue;
            visited[there] = 1;
            queue_push(&q,there);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        edge[u][v] = 1;
    }
    bfs(1);
}