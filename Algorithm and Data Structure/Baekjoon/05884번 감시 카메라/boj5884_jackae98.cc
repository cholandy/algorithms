#include <stdio.h>
#define multiplyY 1000000000
#define INF 0x7fffffff
int n;
bool solved=false;
int Coor[100010];
void solve(int a,int b,int c,int k){
	if(solved || k==2*n){
		solved = true;
		return;
	}
	if(Coor[k]==a || Coor[k]==b || Coor[k]==c || Coor[k+1]==a || Coor[k+1]==b || Coor[k+1] ==c ) solve(a,b,c,k+2);
	if(a==INF){
		solve(Coor[k],b,c,k+2);
		solve(Coor[k+1],b,c,k+2);
		return;
	}
	if(b==INF){
		solve(a,Coor[k],c,k+2);
		solve(a,Coor[k+1],c,k+2);
		return;
	}
	if(c==INF){
		solve(a,b,Coor[k],k+2);
		solve(a,b,Coor[k+1],k+2);
		return;
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<2*n;i+=2){
		scanf("%d %d",&Coor[i],&Coor[i+1]);
		Coor[i+1]*=multiplyY;
	}
	solve(INF,INF,INF,0);
	printf("%d",solved ? 1:0); 
}