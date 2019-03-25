#include <bits/stdc++.h>
using namespace std;
int DP[1025][1025],arr[1025][1025],n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
            DP[i][j]=arr[i][j]+DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1];
        }
    }
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",DP[x2][y2]-DP[x2][y1-1]-DP[x1-1][y2]+DP[x1-1][y1-1]);
    }
}