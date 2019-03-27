#include <bits/stdc++.h>
using namespace std;
 
int n;
int cnt[1005];
vector<pair<int, pair<int, int> > >v;
 
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(v.rbegin(),v.rend());
    int acnt=0;
    for(int i=0;i<n&&acnt<3;++i){
        if(cnt[v[i].second.first]<2){
            printf("%d %d",v[i].second.first,v[i].second.second);
            cnt[v[i].second.first]++;
            ++acnt;
        }
    } 
}