#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma warning(disable:6031)
#define MAX 0xfffff


int n, m, u, v, d, s, pq_t;

typedef struct node{
    node* next;
    int destination;
    int cost;
}node;
node* head[1000];

typedef struct{
    int vertex;
    int cost;
}priority_queue;
priority_queue pq[MAX], tmp;

void pq_push(int vertex, int cost){
    pq[++pq_t].cost = cost;
    pq[pq_t].vertex = vertex;
    for (int i=pq_t; i>1; i/=2){
        if (cost < pq[i/2].cost) pq[i] = pq[i/2];
        else {
            pq[i].cost = cost;
            pq[i].vertex = vertex;
            return;
        }
    }
    pq[1].vertex = vertex;
    pq[1].cost = cost;
}

void pq_pop(){
    pq[1]=pq[pq_t--];
    for (int s=1;;) {
        int e = s*2;
        if (e>pq_t) return;
        if (e+1 <=pq_t && pq[e].cost > pq[e+1].cost) e++;
        if (pq[s].cost > pq[e].cost) {
            tmp = pq[s];
            pq[s] = pq[e];
            pq[e] = tmp;
            s = e;
        } else break;
    }
}

int* dijkstra(int start) {
    int* dist = (int*)malloc(sizeof(int) * (n+1));
    for (int i=1;i<n+1;i++) dist[i]=-1;
    dist[start]=0;
    pq_push(start, dist[start]);
    while (pq[1].vertex!=0){
        int here = pq[1].vertex;
        int heredist = pq[1].cost;
        pq_pop();
        if (heredist > dist[here]) continue;
        node* current_node = head[here];
        for (;current_node;current_node=current_node->next){
            int there = current_node->cost;
            int nextdist = heredist + current_node->cost;
            if (dist[there] == -1 || dist[there]>nextdist) {
                dist[there]=nextdist;
                pq_push(there, nextdist);
            }
        }
    }    
    return dist;
}

void add(node** head, int destination, int cost){
    node* new_node = (node*)malloc(sizeof(node*));
    new_node->destination = destination;
    new_node->cost = cost;
    if (!(*head)) {
        new_node->next = NULL;
        (*head) = new_node;
    } else {
        new_node->next = (*head);
        (*head) = new_node;
    }
    return;
}
int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i=0;i<m;i++){
        scanf("%d %d %d", &u, &v, &d);
        add(&head[u],v,d);
    }
    int* dist = dijkstra(s);
    for (int i=1;i<=n;i++){
        printf("%d\n", dist[i]);
    }
    return 0;
}