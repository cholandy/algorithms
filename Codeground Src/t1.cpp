#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int N; //정점의 개수
int M; //간선의 개수
int u; //정점 u의 번호(출발점)
int v; //정점 v의 번호(도착점
int d; //정점 사이의 가중치(양수면 다익스트라)
int S; //시작 정점의 번호

typedef struct node {
	struct node* next;
	int destination;
	int cost;
} node;
node *adjacentlist[MAX];

struct priority_que {
	int vertex;
	int cost;
} pq[MAX*2], tmp;

int pq_t; // 우선순위 큐의 탑
void add(node** adjacentlist, int destination, int cost); //인접리스트로 전처리
void pq_pop();
void pq_push(int x, int cost);

// Dijkstra Algorithms
int* dijkstra(int start) {
	int *dist = (int*)malloc( sizeof(int) * (N + 1) ); // int 배열 동적할당. N+1인 것은 시작점이랑 인덱스랑 맞추기 위해
	for (int i = 1; i < N + 1; i++) {
		dist[i] = -1;
	}
	dist[start] = 0;
	pq_push(start, dist[start]);
	while (pq[1].vertex != 0) {
		int here = pq[1].vertex;
		int heredist = pq[1].cost;
		pq_pop();
		if (heredist > dist[here]) continue;
		node *current_node = adjacentlist[here];
		for (; current_node; current_node = current_node->next) {
			int there = current_node->destination;
			int nextdist = heredist + current_node->cost;
			if (dist[there] == -1 || dist[there] > nextdist) {
				dist[there] = nextdist;
				pq_push(there, nextdist);
			}
		}
	}
	return dist;
}

int main()
{
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &d);
		add(&adjacentlist[u], v, d);
	}
	int* dist = dijkstra(S);
	for (int i = 1; i <= N; i++) {
		printf("%d\n", dist[i]);
	}
	return 0;
}

void add(node** adjacentlist, int destination, int cost) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->destination = destination;
	new_node->cost = cost;
	if (!(*adjacentlist)) {
		new_node->next = NULL;
		(*adjacentlist) = new_node;
	}
	else {
		new_node->next = (*adjacentlist);
		(*adjacentlist) = new_node;
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
		}
		else break;
	}
}

void pq_push(int vertex, int cost) {
	pq[++pq_t].cost = cost;
	pq[pq_t].vertex = vertex;
	for (int i = pq_t; i > 1; i /= 2) {
		if (cost < pq[i / 2].cost) pq[i] = pq[i / 2];
		else {
			pq[i].vertex = vertex;
			pq[i].cost = cost;
			return;
		}
	}
	pq[1].vertex = vertex;
	pq[1].cost = cost;
}