#include <stdio.h>
#include <stdlib.h>
#define MAX 55
#define INF 987654321
typedef struct node {
    struct node* next;
    int value;
    int weight;
} node;

void add(node** head, int value, int weight);

int N, M, u, v, d, S;
node *head[MAX];
int* bellmanFord(int start) {
    int *upper = (int*)malloc(sizeof(int)*(N + 1));
    int updated = 0;
    node *current_node;
    int here,there;
    int heredist,nextcost;
    for (int i = 1; i <= N; i++) {
        upper[i] = INF;
    }
    // first : dist , second : vertex_pos
    upper[start] = 0;
    for (int iter = 0; iter < N; iter++) {
        updated = 0;
        for (int here = 1; here <= N; here++) {
            current_node = head[here];
            for (; current_node; current_node=current_node->next) {
                int there = current_node->value;
                int	nextcost = upper[here] + current_node->weight;
                if (upper[there] > nextcost) {
                    upper[there] = nextcost;
                    updated = 1;
                }
            }
        }
        if (!updated) break;
    }
    if (updated) return NULL;
    return upper;
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &d);
        add(&head[u], v, d);
    }
    int *dist = bellmanFord(S);
    if (dist == NULL)
        puts("-1");
    else {
        for (int i = 1; i <= N; i++) {
            printf("%d\n", dist[i]);
        }
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