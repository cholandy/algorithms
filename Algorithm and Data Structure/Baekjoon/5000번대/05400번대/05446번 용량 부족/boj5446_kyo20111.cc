#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int chk[40200],t,chk2[40200];
int fnd(int cur,map<int,int> *x){
    if(chk[cur]==1) return 1;
    if(chk[cur]==2) return 0;
    int re=chk2[cur];
    for(int i=1;i<='z';i++) if(x[cur].count(i)) re+=fnd(x[cur][i],x);
    return re;
}
int main(){
    scanf("%d",&t);
    while(t--){
        int n,cnt=0;
        map<int,int> trie[40200];
        for(int k=1;k<=2;k++){
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
                char s[32];
                scanf("%s",s);
                int cur=0,len=strlen(s);
                for(int j=0;j<len;j++){
                    if(trie[cur].count(s[j])==0) trie[cur][s[j]]=++cnt;
                    cur=trie[cur][s[j]];
                    chk[cur]|=k;
                }
                if(k==1) chk2[cur]=1;
            }
        }
        chk[0]=3;
        printf("%d\n",((!n)?1:fnd(0,trie)));
        for(int i=0;i<=cnt;i++) chk2[i]=chk[i]=0;
    }
}
