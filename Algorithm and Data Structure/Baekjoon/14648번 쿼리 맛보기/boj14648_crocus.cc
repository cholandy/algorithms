#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
ll init(vector<int> &arr, vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
 
    int mid = (start + end) / 2;
 
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}
 
void update(vector<ll> &tree, int node, int start, int end, int idx, int diff)
{
    if (!(start <= idx && idx <= end))
        return;
 
    tree[node] += diff;
 
    if (start == end)
        return;
 
    int mid = (start + end) / 2;
 
    update(tree, node * 2, start, mid, idx, diff);
    update(tree, node * 2 + 1, mid + 1, end, idx, diff);
}
 
ll query(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node];
 
    int mid = (start + end) / 2;
 
    return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}
 
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
 
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
 
    vector<int> arr(n + 1);
    vector<ll> tree(tree_size);
 
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    init(arr, tree, 1, 0, n - 1);
 
    while (q--)
    {
        int num;
        scanf("%d", &num);
 
        if (num == 1)
        {
            int a, b;
            scanf("%d %d", &a, &b);
 
            a--, b--;
            printf("%lld\n", query(tree, 1, 0, n - 1, a, b));
 
            int diff1 = arr[b] - arr[a];
            update(tree, 1, 0, n - 1, a, diff1);
 
            int diff2 = arr[a] - arr[b];
            update(tree, 1, 0, n - 1, b, diff2);
 
            arr[a] += diff1;
            arr[b] += diff2;
        }
 
        else if (num == 2)
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
 
            a--, b--, c--, d--;
            printf("%lld\n", query(tree, 1, 0, n - 1, a, b) - query(tree, 1, 0, n - 1, c, d));
        }
    }
 
    return 0;
}