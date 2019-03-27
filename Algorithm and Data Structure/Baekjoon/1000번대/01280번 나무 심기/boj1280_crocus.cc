#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
const int MOD = 1e9 + 7;
 
void update(vector<pair<ll, ll> > &tree, int node, int start, int end, int idx)
{
    if (!(start <= idx && idx <= end))
        return;
 
    tree[node].first += 1;
    tree[node].second += idx;
 
    if (start == end)
        return;
 
    int mid = (start + end) / 2;
    update(tree, node * 2, start, mid, idx);
    update(tree, node * 2 + 1, mid + 1, end, idx);
}
 
long long sumQuery(vector<pair<ll, ll> > &tree, int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node].second;
 
    int mid = (start + end) / 2;
    return sumQuery(tree, node * 2, start, mid, left, right) + sumQuery(tree, node * 2 + 1, mid + 1, end, left, right);
}
 
long long cntQuery(vector<pair<ll, ll> > &tree, int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node].first;
 
    int mid = (start + end) / 2;
    return cntQuery(tree, node * 2, start, mid, left, right) + cntQuery(tree, node * 2 + 1, mid + 1, end, left, right);
 
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    vector<int> arr(n + 1);
 
    long long ans = 1;
    int limit = -1;
 
    vector<int> vc;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        limit = max(limit, arr[i]);
        vc.push_back(limit);
    }
 
    int h = (int)ceil(log2(200000));
    int tree_size = (1 << (1 + h));
    vector<pair<ll, ll>> tree(tree_size);
 
    for (int i = 0; i < n; i++)
    {
        update(tree, 1, 0, limit, arr[i]);
        
        long long left = cntQuery(tree, 1, 0, limit, 0, arr[i]) * arr[i] - sumQuery(tree, 1, 0, limit, 0, arr[i]);
        long long right = sumQuery(tree, 1, 0, limit, arr[i] + 1, limit) - cntQuery(tree, 1, 0, limit, arr[i] + 1, limit)*arr[i];
 
 
        long long get = (left % MOD + right % MOD) % MOD;
 
        if(i)
            ans = (ans * get) % MOD;
    }
 
    cout << ans % MOD << endl;
    return 0;
}
 