#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef struct _INFO_
{
    int idx;
    int ans;
    int val;
}INFO;
 
INFO info[1002];
 
bool compVal(const INFO &a, const INFO &b)
{
    if(a.val != b.val) // 사전 순 정렬
        return a.val < b.val;
    return a.idx < b.idx;
}
 
bool compIdx(const INFO &a, const INFO &b)
{
    return a.idx < b.idx;
}
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &info[i].val);
        info[i].idx = i;
    }
 
    sort(info, info + n, compVal);
 
    for (int i = 0; i < n; i++)
        info[i].ans = i;
 
    sort(info, info + n, compIdx);
 
    for (int i = 0; i < n; i++)
        printf("%d ", info[i].ans);
 
    return 0;
}