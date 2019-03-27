#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
 
LL init(vector<LL> &a, vector<LL> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    else {
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) +
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
    }
}
 
void update(vector<LL> &tree, int node, int start, int end, int index, LL diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
 
LL sum(vector<LL> &tree, int node,int start,int end,int left,int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
        sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
 
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector <LL> a(n);
    int h = (int)ceil(log2(n));
    vector<LL> tree((1 << h + 1));
    m += k;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
 
    //트리 만들기
    init(a, tree, 1, 0, n - 1);
 
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d",&x,&y,&z);
        if (x == 1) {
            y--;
            long long diff = z - a[y];
            a[y] = z;
            update(tree, 1, 0, n - 1, y, diff);
        }
        else {
            printf("%lld\n", sum(tree, 1, 0, n - 1, y - 1, z - 1));
        }
    }
    return 0;
}
