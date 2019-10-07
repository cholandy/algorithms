#include <bits/stdc++.h>

using namespace std;

#define MAXX 10001

typedef long long ll;

struct Edge {
    int v1;
    int v2;
    int weight;
    bool operator < (Edge & e) { 
        return weight < e.weight;
    }
};
int v, e;
int parent[MAXX];
int setSize[MAXX];
ll weights = 0;
void init(); 
int find_(int n); 
void union_(int a, int b); 

int main() {
    cin >> v >> e;
    vector < Edge > edgeV;
    for (int i = 0; i < e; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        edgeV.push_back({a,b,c});
    } 
    sort(edgeV.begin(), edgeV.end()); 
    init();
    for (int i = 0; i < e; i++) { 
        if (find_(edgeV[i].v1) != find_(edgeV[i].v2)) {
            union_(edgeV[i].v1, edgeV[i].v2);
            weights += edgeV[i].weight;
        }
    }
    cout << weights << '\n';
}
void init() {
    for (int i = 0; i < v; i++) {
        parent[i] = i;
        setSize[i] = 0;
    }
}
int find_(int n) {
    if (n == parent[n]) {
        return n;
    }
    return parent[n] = find_(parent[n]);
}
void union_(int a, int b) {
    a = find_(a);
    b = find_(b);
    if (a != b) { 
        if (setSize[a] < setSize[b]) {
            swap(a, b);
        }
        parent[b] = a;
        setSize[a] += setSize[b];
        setSize[b] = 0;
    }
}