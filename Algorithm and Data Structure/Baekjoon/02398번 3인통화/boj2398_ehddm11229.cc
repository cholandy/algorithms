#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,int> > vli;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<db,db> > vdd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const db PI = acos(-1);

int COST[1001][1001];
vector<vector<int> > adj;
int parent[1001][1001];
int DIST[1001][1001];

int main(){

    std::ios::sync_with_stdio(false);

    int n,m;
    scanf("%d %d",&n,&m);

    adj.resize(n+1);

    int a,b,c,x,y,z;
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
    
        COST[a][b]=COST[b][a]=c;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    scanf("%d %d %d",&a,&b,&c);

    vii last;
    memset(DIST,0x3f,sizeof(DIST));

    // dist, here, from
    priority_queue<pair<int,pii> > q;
    q.push(mp(0,mp(a,a)));
    q.push(mp(0,mp(b,b)));
    q.push(mp(0,mp(c,c)));

    parent[a][a]=a;
    parent[b][b]=b;
    parent[c][c]=c;

    DIST[a][a]=DIST[b][b]=DIST[c][c]=0;

    while(!q.empty()){

        int here = q.top().second.first;
        int from = q.top().second.second;
        int dist = -q.top().first; q.pop();

        if(DIST[here][from]<dist) continue;

        for(int i=0;i<adj[here].size();i++){
            int next = adj[here][i];
            int cost = COST[here][next]+dist;

            if(DIST[next][from]>cost){
                DIST[next][from]=cost;
                parent[next][from]=here;
                q.push(mp(-cost,mp(next,from)));
            }
        }
    }

    int pos=1, xmin=1e9;
    for(int i=1;i<=n;i++){
        if(xmin>DIST[i][a]+DIST[i][b]+DIST[i][c]){
            xmin=DIST[i][a]+DIST[i][b]+DIST[i][c];
            pos=i;
        }
    }

    int pp=pos;
    int t,k;
    vii result;
    for(;pp!=a;pp=parent[pp][a]){
        t = parent[pp][a];
        k = pp;
        if(t>k) swap(t,k);
        result.pb(mp(t,k));
    }
    pp=pos;
    for(;pp!=b;pp=parent[pp][b]){
        t = parent[pp][b];
        k = pp;
        if(t>k) swap(t,k);
        result.pb(mp(t,k));
    }
    pp=pos;
    for(;pp!=c;pp=parent[pp][c]){
        t = parent[pp][c];
        k = pp;
        if(t>k) swap(t,k);
        result.pb(mp(t,k));
    }
    
    sort(all(result));
    result.resize(unique(all(result))-result.begin());

    int cost=0;
    for(int i=0;i<result.size();i++)
        cost += COST[result[i].first][result[i].second];

    printf("%d %d\n", cost,result.size());
    for(int i=0;i<result.size();i++)
        printf("%d %d\n",  result[i].first,result[i].second);

    return 0;
}
