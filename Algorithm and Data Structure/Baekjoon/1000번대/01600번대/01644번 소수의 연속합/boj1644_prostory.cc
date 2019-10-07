#include<bits/stdc++.h>
using namespace std;
int sosu[4000005],arr[2000005],n,m,sum,re,s,e;
//sosu ㅋㅋㅋㅋㅋ
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(!sosu[i]){
            arr[m++]=i;
            for(int j=i;j<=n;j+=i) sosu[j]=1;
        }
    }
    while(1){
        if(sum>=n) sum-=arr[s++];
        else if(e==m) break;
        else sum+=arr[e++];
        if(sum==n) re++;
    }
    printf("%d",re);
}
