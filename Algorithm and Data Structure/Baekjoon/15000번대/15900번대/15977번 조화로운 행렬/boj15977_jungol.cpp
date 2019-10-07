#include <bits/stdc++.h>

#define LM 200005

using namespace std;

int M, N, D[LM], ans;

struct data {
    int a,b,c;
    bool operator<(const data &r) const {return a < r.a;}
}A[LM];

void input() {
    scanf("%d %d", &M, &N);
    int i, j;
    for (i=0;i<N;++i) scanf("%d", &A[i].a);
    for (i=0;i<N;++i) scanf("%d", &A[i].b);
    if (M>2) for (i=0;i<N;++i) scanf("%d", &A[i].c);

    sort(A, A+N);
}
map<int, int> lst[LM];
int search_in(int s, int e, int x, int y) {
    while (s <= e) {
        int m = (s+e) / 2;
        auto p = lst[m].lower_bound(x);
        if (p != lst[m].begin() && (--p)-> second < y) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    for (auto p = lst[s].lower_bound(x); p != lst[s].end() && p->second > y;)
        lst[s].erase(p++);
    lst[s][x] = y;
    return s;
}
int main() {
    // freopen("input.txt", "r", stdin);
    input();

    if (M==2) {
        vector<int> lst;
        for (int i=0; i<N;++i) {
            auto p = lower_bound(lst.begin(), lst.end(), A[i].b);
            if (p==lst.end()) lst.push_back(A[i].b);
            else *p = A[i].b;
        }
        ans = lst.size();
    } else {
        lst[0][0] = 0;
        for (int i=0;i<N;++i) {
            if (search_in(0, ans, A[i].b, A[i].c) > ans) ans++;
        }
    }

    // for (int i=1;i<=N;++i) {
    //     for (int j=0; j<i; j++) {
    //         if (A[i].b > A[j].b && A[i].c >= A[j].c && D[i] < D[j] + 1) {
    //             D[i] = D[j] + 1;
    //         } 
    //     ans = max(ans, D[i]);
    //     }
    // }
        
    printf("%d\n", ans);
    return 0;
}
