#include <bits/stdc++.h>
using namespace std;
int n,m;
int psum[100005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&psum[i]);
        psum[i]+=psum[i-1];
    }
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        printf("%d",psum[y]-psum[x-1]);
    }
}