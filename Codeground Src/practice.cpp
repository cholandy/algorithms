#include <stdio.h>
#include <stdlib.h>

#define MAX 10001;

typedef struct node {
    struct node* next;
    int value;
    int weight;
} Node;

int N, M, u, v, d, S;
// 정점의 개수
// 

struct priority_queue {
    int x, cost;
} pq[1001], tmp;




int* dijkstra(int start) {
    int* dist = (int*)malloc(sizeof(int) * (N+1));
    for (int i=1; i<=N; i++) 
        dist[i] = -1;
    dist[start] = 0;
}

int pq_t = 0; // priority_queue_top

void pq_push(int x, int cost) {
    pq[++pq_t].cost = cost;
    pq[pq_t].x = x;
    for (int i=pq_t; i>1; i/=2) {
        if (cost < pq[i/2].cost) pq[i] = pq[1/2];
        else {
            pq[i].x = x;
            pq[i].cost = cost;
            return;
        }
    }
    pq[1].x = x;
    pq[1].cost = cost;
}

void pq_pop() {
    pq[1] = pq[pq_t--];
    for (int s = 1;;) {
        int e = s*2;
        if (e>pq_t) return;
        if (e+1 <= pq_t && qp[e].cost > pq[e+1].cost) e++;
        if (pq[s].cost > pq[e].cost) {
            tmp = pq[s];
            pq[s] = pq[e];
            pq[e] = tmp;
            s = e;
        } else break;
    }
}