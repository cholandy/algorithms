#include <stdio.h>
struct al{
    int e,nx;
}a[200010];
int st[100010],chk[100010],p[100010],cycle[100010],t;
void make_al(int s,int e){a[++t].nx=st[s],a[t].e=e,st[s]=t;}
void get_cycle(int s,int x){
    ++cycle[x];
    for(;;){
        ++cycle[s];
        s=p[s];
        if(s==x)return;
    }
}
void DFS(int s){
    int i;
    chk[s]=1;
    for(i=st[s];i;i=a[i].nx)if(chk[a[i].e]){
        if(p[s]==a[i].e)continue;
        get_cycle(s,a[i].e);
    }
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]){
        p[a[i].e]=s;
        DFS(a[i].e);
    }
}
int main(){
    int i,n,m,s,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e),make_al(e,s);
    }
    DFS(1);
    for(i=1;i<=n;++i)if(cycle[i]>1){
        puts("Not cactus");
        return 0;
    }
    puts("Cactus");
    return 0;
}