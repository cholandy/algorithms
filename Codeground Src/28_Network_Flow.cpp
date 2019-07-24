#include <stdio.h>
#include <stdlib.h>

typedef struct network_edge {
    int to, capacity, flow;
    struct network_edge* residual_edge;
} network_edge;

typedef struct node {
    struct node* next;
    struct network_edge* edge;
} node;

network_edge* make_edge(int to, int capacity, int flow);
void add_edge(int from, int to, int capacity);
int find_path(int cur, int addible_flow);

int min(int a, int b) {
    return a < b ? a : b;
}

node* adj[101];
int src, sink, chk[101];

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    for(int i = 1; i <= v; i++) {
        adj[i] = (node*)malloc(sizeof(node));
        adj[i]->next = NULL;
    }

    scanf("%d %d", &src, &sink);

    for(int i = 0; i < e; i++) {
        int from, to, capacity;
        scanf("%d %d %d", &from, &to, &capacity);
        add_edge(from, to, capacity);
    }

    int ans = 0, added_flow;
    while(added_flow = find_path(src, 101)) {
        ans += added_flow;
        for(int i = 1; i <= v; i++) {
            chk[i] = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}

network_edge* make_edge(int to, int capacity, int flow) {
    network_edge* edge = (network_edge*)malloc(sizeof(network_edge));
    edge->to = to;
    edge->capacity = capacity;
    edge->flow = flow;
    return edge;
}

void add_edge(int from, int to, int capacity) {
    node* actual = (node*)malloc(sizeof(node));
    node* residual = (node*)malloc(sizeof(node));

    actual->edge = make_edge(to, capacity, 0);
    residual->edge = make_edge(from, 0, 0);
    actual->edge->residual_edge = residual->edge;
    residual->edge->residual_edge = actual->edge;

    actual->next = adj[from]->next;
    adj[from]->next = actual;
    residual->next = adj[to]->next;
    adj[to]->next = residual;
}

int find_path(int cur, int addible_flow) {
    if(cur == sink) return addible_flow;
    chk[cur] = 1;

    for(node* current = adj[cur]->next; current != NULL; current = current->next) {
        network_edge* edge = current->edge;
        if(chk[edge->to] == 1 || edge->capacity - edge->flow == 0) continue;

        int added = find_path(edge->to, min(addible_flow, edge->capacity - edge->flow));
        if(added) {
            edge->flow += added;
            edge->residual_edge->flow -= added;
            return added;
        }
    }
    return 0;
}