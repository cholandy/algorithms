#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
 
using namespace std;
 
int l[100002], r[100002];
vector<int> tree;
 
void update(int node, int start, int end, int idx)
{
    if (!(start <= idx && idx <= end))
        return;
 
    tree[node] += 1;
 
    if (start != end)
    {
        int mid = (start + end) / 2;
        update( node * 2, start, mid, idx);
        update( node * 2 + 1, mid + 1, end, idx);
    }
}
 
int query(int node, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    return query( node * 2, start, mid, left, right) + query( node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
    int n;
    scanf("%d", &n);
 
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
 
    vector<int> arr(n + 1);
    tree = vector<int>(tree_size);
 
    long long ans = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    for (int i = 0; i < n; i++)
    {
        l[i] = query( 1, 0, n - 1, arr[i], n - 1);
        update( 1, 0, n - 1, arr[i] - 1);
    }
        
    tree = vector<int>(tree_size);
 
    for (int i = n - 1; i >= 0; i--)
    {
        r[i] = query( 1, 0, n - 1, 0, arr[i] - 2);
        update( 1, 0, n - 1, arr[i] - 1);
    }
 
    for (int i = 0; i < n; i++)
        ans += 1LL * l[i] * r[i];
    
    printf("%lld", ans);
 
    return 0;
}