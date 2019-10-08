#include <cstdio>
using namespace std;
const int MAX_N = 1024;
const int MAX_M= 100000;
typedef long long ll;
int N,M;
ll tree[MAX_N+1][MAX_N+1]={0};
void update (int x, int y , ll val){
    int temp_x = x;
    while (temp_x<=N) {
        int temp_y = y;
        while (temp_y<=N) {
            tree[temp_x][temp_y]+=val;
            temp_y+=(temp_y&-temp_y);
        }
        temp_x+=(temp_x&-temp_x);
    }
}
ll sum ( int x,int y){
    ll ret =0;
    int temp_x =x;
    while (temp_x>0) {
        int temp_y=y;
        while (temp_y>0) {
            ret += tree[temp_x][temp_y];
            temp_y-=(temp_y&-temp_y);
        }
        temp_x-=(temp_x&-temp_x);
    }
    return ret;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i =1 ;i <=N ; i++){
        for(int j =1;j<=N;j++){
            ll num =0;
            scanf("%lld",&num);
            update(i,j,num);
        }
    }
    for(int i =0 ; i < M ; i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("%lld\n",sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1));
    }
}
