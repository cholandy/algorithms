#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <set>
#include <list>
#include <utility>
#include <functional>
#define MAX 55
#define INF 987654321
#define MOD 1000000
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
 
int n, m, t;
char a[MAX], b[MAX];
vector<pi> v;
 
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s%s", a,b);
    scanf("%d", &t);
    for (int i = strlen(a) - 1; i >= 0; i--)
        v.push_back(make_pair(a[i], 1));
    for (int i = 0; i < strlen(b); i++)
        v.push_back(make_pair(b[i], 2));
    for (int i = 0; i < t; i++)
        for(int k=0;k<v.size()-1;k++)
            if (v[k].second == 1 && v[k + 1].second == 2)
            {
                swap(v[k], v[k + 1]);
                k++;
            }
    for (int i = 0; i < v.size(); i++)
        printf("%c", v[i].first);
    return 0;
}