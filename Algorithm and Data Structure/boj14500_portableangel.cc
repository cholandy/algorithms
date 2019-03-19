#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a[505][505], n, m;

int p[5][3][4]={
	{{1,1,1,1},
	{0,0,0,0},
	{0,0,0,0}},
	{{1,1,0,0},
	{1,1,0,0},
	{0,0,0,0}},
	{{1,0,0,0},
	{1,0,0,0},
	{1,1,0,0}},
	{{1,0,0,0},
	{1,1,0,0},
	{0,1,0,0}},
	{{1,1,1,0},
	{0,1,0,0},
	{0,0,0,0}}
};

int f() {
	int res=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			for(int t=0;t<5;t++) {
				int rr=0;
				for(int r=i;r<i+3;r++) {
					for(int c=j;c<j+4;c++)
						rr+=p[t][r-i][c-j]*a[r][c];
				}
				res=max(res,rr);
			}
		}
	}
	return res;
}

int t[500][500];

void rot() {
	memset(t,0,sizeof(t));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			t[j][n-1-i]=a[i][j];
	}
	memset(a,0,sizeof(a));
	swap(n,m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			a[i][j]=t[i][j];
	}
}

void rev() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m/2;j++)
			swap(a[i][j],a[i][m-1-j]);
	}
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	int res=0;
	for(int it=0;it<8;it++) {
		res=max(res,f());
		rot();
		if(it==3) rev();
	}
	printf("%d\n",res);
	return 0;
}