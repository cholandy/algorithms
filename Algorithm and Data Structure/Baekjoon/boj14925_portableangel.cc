#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000][1000], n, m;
int l[1000], r[1000], h[1001];

int process() {
	vector<int> v;
	int res=0;
	for(int i=0;i<=m;i++) {
		while(!v.empty() && h[v.back()]>=h[i]) {
			int j=v.back();
			v.pop_back();
			res=max(res,min(h[j],(v.empty()?i:i-1-v.back())));
		}
		v.push_back(i);
	}
	return res;
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	int res=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j]) h[j]=0;
			else h[j]++;
		}
		res=max(res,process());
	}
	printf("%d\n",res);
	return 0;
}