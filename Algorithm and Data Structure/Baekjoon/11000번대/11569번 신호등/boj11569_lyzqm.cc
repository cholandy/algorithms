#include <cstdio>

#include <queue>

#include <vector>

#include <functional>

#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<ll, pair<int,int> > P;        

#define INF 987654321987654321

#define mp(a,b) make_pair(a,b)

#define mt(a,b,c) mp(a,mp(b,c))

int N, M, S, D;

vector<vector<pair<int,ll> > > adj;            //정렬 되있음        next, cost

vector<int> delay;                //교차로에서의 주기

ll dijkstra(int start, int end){

    priority_queue<P, vector<P>, greater<P>> pq;        //cost, from, here

    vector<ll> dist(N + 1, INF);


    dist[start] = 0;


    //처음 start->ver 연결된 지점은 교차신호 상관없음

    for (auto n : adj[start]){

        pq.push(mt(n.second, start, n.first));

        dist[n.first] = n.second;

    }


    while (!pq.empty()){

        int here = pq.top().second.second;

        int from = pq.top().second.first;

        ll cost = pq.top().first;

        pq.pop();


        if (here == end) return dist[end];


        for (auto n : adj[here]){

            int next = n.first;

            ll ncost = n.second;

            

            //주기는 here교차로의 size에 의존함

            //from -> here -> next ,from이 here교차로의 몇번째 order인지 알아야함

            ll T = cost;            //시간

            ll P = delay[here];        //delay

            ll size = adj[here].size();

            int order;            //가고자하는 패턴번호


            for (order = 0; order < adj[here].size(); order++)        //가고자하는 패턴번호를 구함

                if (adj[here][order].first == from) break;

            

            //최종 T를 구함

            int curr = (T / P) % size;        //현재 패턴번호

            

            if (order != curr)

                T = (T / P + (order + size - curr) % size) * P;            //가장 근접한 T로 만듬


            if (dist[next] > T + ncost){

                dist[next] = T + ncost;

                pq.push(mt(dist[next], here, next));

            }

        }

    }

    return dist[end];

}

int main(){

    int T;

    scanf("%d", &T);


    while (T--){

        scanf("%d%d%d%d", &N, &M, &S, &D);

        

        adj = vector<vector<pair<int, ll> > >(N + 1);

        delay = vector<int>(N + 1);

        for (int m = 0; m < M; m++){

            int u, v, d;

            scanf("%d%d%d", &u, &v, &d);

            adj[u].push_back(mp(v, (ll)d));

            adj[v].push_back(mp(u, (ll)d));

        }

        for (int n = 1; n <= N; n++){

            scanf("%d", &delay[n]);

            sort(adj[n].begin(), adj[n].end());

        }

        ll ans = dijkstra(S, D);

        printf("%lld\n", ans == INF ? -1 : ans);

    }

    return 0;

}
