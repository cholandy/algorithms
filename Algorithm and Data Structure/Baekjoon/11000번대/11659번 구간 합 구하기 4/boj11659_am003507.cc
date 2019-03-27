#include <cstdio>
using namespace std;
const int MAX_N = 262200;
const int MAX_M = 100000;
int N,M,start;
int seg[MAX_N];
void update(int idx,int val){
    int index = start+idx;
    seg[index]=val;
    while (index>1) {
        index/=2;
        seg[index] =seg[index*2]+seg[index*2+1];
    }
}
int sum (int L,int R,int idx, int temp_L,int temp_R){
    if( L>temp_R || R<temp_L)return 0;
    if(L<=temp_L&&temp_R<=R) return seg[idx];
    int mid = (temp_L+temp_R)/2;
    return sum(L,R,idx*2,temp_L,mid)+sum(L,R, idx*2+1, mid+1, temp_R);
}
int main(){
    scanf("%d %d",&N,&M);
    for(start=1;start<N;start*=2);
    for(int i =0 ;i < N; i++){
        int num;
        scanf("%d",&num);
        update(i, num);
    }
    for(int i =0 ;i < M ; i++){
        int a, b;
        scanf("%d %d",&a,&b);
        a--;b--;
        if(a>b){
            int temp = a;
            a= b;
            b=temp;
        }
        printf("%d\n",sum(a,b,1,0,start-1));
    }
}
