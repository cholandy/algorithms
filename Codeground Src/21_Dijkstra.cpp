#include <stdio.h>
#include <stdlib.h>
#define MAX 55

typedef struct node {
    struct node* next;
    int value;
    int weight;
} node;

struct priority_queue {
    int x, cost;
} pq[MAX*2], tmp;

int pq_t;
void add(node** head, int value, int weight);
void pq_pop();
void pq_push(int x, int cost);

int N, M, u, v, d, S;
node *head[MAX];
int* Dijkstra(int start) {
    int *dist = (int*)malloc(sizeof(int)*(N+1));
    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }
    // first : dist , second : vertex_pos
    dist[start] = 0;
    pq_push(start, dist[start]);
    while (pq[1].x!=0) {
        int here = pq[1].x;
        int heredist = pq[1].cost;
        pq_pop();
        if (heredist > dist[here]) continue;
        node *current_node = head[here];
        for (; current_node; current_node=current_node->next) {
            int there = current_node->value;
            int nextdist = heredist + current_node->weight;
            if (dist[there] == -1 || dist[there] > nextdist) { //최단 거리 갱신
                dist[there] = nextdist;
                pq_push(there, nextdist);
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &d);
        add(&head[u], v, d);
    }
    int *dist = Dijkstra(S);
    for (int i = 1; i <= N; i++) {
        printf("%d\n", dist[i]);
    }
    return 0;
}

void add(node** head, int value, int weight) {
    node* new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->weight = weight;
    if (!(*head)) {
        new_node->next = NULL;
        (*head) = new_node;
    } else {
        new_node->next = (*head);
        (*head) = new_node;
    }
    return;
}

void pq_pop() {
    pq[1] = pq[pq_t--];
    for (int s = 1;;) {
        int e = s * 2;
        if (e > pq_t) return;
        if (e + 1 <= pq_t && pq[e].cost > pq[e + 1].cost) e++;
        if (pq[s].cost > pq[e].cost) {
            tmp = pq[s];
            pq[s] = pq[e];
            pq[e] = tmp;
            s = e;
        } else break;
    }
}

void pq_push(int x, int cost) {
    pq[++pq_t].cost = cost;
    pq[pq_t].x = x;
    for (int i = pq_t; i > 1; i /= 2) {
        if (cost < pq[i / 2].cost) pq[i] = pq[i / 2];
        else {
            pq[i].x = x;
            pq[i].cost = cost;
            return;
        }
    }
    pq[1].x = x;
    pq[1].cost = cost;
}