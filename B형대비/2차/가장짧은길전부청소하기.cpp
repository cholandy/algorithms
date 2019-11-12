// G = (V, E) 그래프에서, 어떤 지점 S로부터 출발하여 다른 모든 정점으로 가는 최단 경로들을 나타낸 그래프를 shortest path DAG라 한다.
// DAG란 Directed Acyclic Graph의 약자로, 방향성이 있고, 사이클이 존재하지 않는 그래프이다. 
// 필요한 알고리즘: 다익스트라
#include <stdio.h>

#define NM 200005
#define NE 500005

typedef long long int ll;

struct HEAP{
    int idx;
    ll cost;
    HEAP(){idx=0,cost=0;}
    HEAP(int idx,ll cost):idx(idx),cost(cost){}
} heap[NE*3];

int HN;

struct LIST{
    int v;
    ll cost;
    LIST* next;
}edge[NE*2];

LIST* mem[NM];
 
FILE *in=stdin,*out=stdout;
int n,m;
ll dist[NM];
void input(){
    fscanf(in,"%d %d",&n,&m);
    for (int i=1;i<=n;i++) mem[i]=nullptr;
    for(int i=1;i<=m;i++){
        int u,v,c;
        fscanf(in,"%d %d %d",&u,&v,&c);
        edge[i].v=v, edge[i].cost=c, edge[i].next=mem[u];
        edge[i+m].v=u, edge[i+m].cost=c, edge[i+m].next=mem[v];
       
        mem[u]=&edge[i];
        mem[v]=&edge[i+m];
    }
}

void push(HEAP x){
    heap[++HN] = x;
    int i = HN;
    while(i>1){
        if (heap[i/2].cost <= heap[i].cost) break;
        HEAP t = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = t;
        i/=2;
    }
}

HEAP pop(){
    HEAP res = heap[1];
    heap[1] = heap[HN--];
    int i = 1;
    while(i*2<=HN){
        ll left = heap[i*2].cost;
        ll right = heap[i*2+1].cost;
        if (i*2+1 > HN) right=1e15;
        if(left<=right){
            if(heap[i].cost>left){
                HEAP t = heap[i];
                heap[i]=heap[i*2];
                heap[i*2]=t;
                i=i*2;
            }else break;
        }
        else{
            if(heap[i].cost>right){
                HEAP t = heap[i];
                heap[i]=heap[i*2+1];
                heap[i*2+1]=t;
                i=i*2+1;
            }else break;
        }
    }
    return res;
}

void dijkstra(){
    for (int i=1;i<=n;i++) dist[i]=1e15;
    dist[1]=0;
    HN=0;
    push(HEAP(1,0));
    while (HN){
        HEAP x = pop();
        if (dist[x.idx] != x.cost) continue;
        for(LIST* p=mem[x.idx]; p!=nullptr; p=p->next){
            if(dist[p->v]>dist[x.idx]+p->cost){
                dist[p->v]=dist[x.idx]+p->cost;
                push(HEAP(p->v,dist[p->v]));
            }
        }
    }
}

void pro(){
    dijkstra();
    ll ans=0;
    for(int i=2;i<=n;i++){
        ll min=1e15;
        for (LIST* p = mem[i]; p!=nullptr ; p=p->next){
            if(dist[p->v]+p->cost==dist[i]){
                if (min > p->cost) min=p->cost;
            }
        }
        ans+=min;
    }
    fprintf(out,"%lld\n",ans);
}

int main(){
    int TT; fscanf(in,"%d",&TT);
    for(int tt=1;tt<=TT;tt++){
        input();
        fprintf(out,"#%d ",tt);
        pro();
    }
    return 0;
}