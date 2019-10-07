#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int n,a,b,c;
vector<pair<int, int>> x,y,z;
//long long planet[100001][3];
long long INF = 999999999999;
vector<pair<long long, long long>> adj[100001];
  
struct DisjointSet {
    vector<int> parent, rank;
  
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
  
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
  
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        if(rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
    }
};
  
long long kruskal()
{
    long long ret = 0;
    //vector<pair<int,int> > selected;
    vector<pair<long long,pair<long long,long long> > > edges;
      
    for(int i = 0; i < n; i++)
        for(int j = 0; j < adj[i].size(); j++)
            {
                edges.push_back(make_pair(adj[i][j].second, make_pair(i,adj[i][j].first)));
            }
    sort(edges.begin(), edges.end());
    DisjointSet d(n);
    for(int i = 0; i < edges.size(); i++)  {
        long long cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(d.find(u) == d.find(v))
            continue;
        d.merge(u,v);
        //selected.push_back(make_pair(u,v));
        ret += cost;
    }
    return ret;
}
  
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        x.push_back(make_pair(a,i)); //벡터에 값을 입력받음.
        y.push_back(make_pair(b,i));
        z.push_back(make_pair(c,i));
    }
    sort(x.begin(), x.end()); //정렬
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    //for(int i=0;i<n;i++)
    //  cout<<x[i].first<<" "<<x[i].second<<endl;
    //cout<<endl;
  
    for(int i=0;i<n-1;i++) //요기가 포인트.
    {
        adj[x[i].second].push_back(make_pair(x[i+1].second, abs(x[i].first - x[i+1].first)));
        adj[y[i].second].push_back(make_pair(y[i+1].second, abs(y[i].first - y[i+1].first)));
        adj[z[i].second].push_back(make_pair(z[i+1].second, abs(z[i].first - z[i+1].first)));
    }
    //adj[a-1].push_back(make_pair(b-1,c));//a~b가는데 c비용이 든다.
    cout<<kruskal()<<endl;
}

