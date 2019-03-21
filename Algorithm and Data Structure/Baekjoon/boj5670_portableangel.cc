#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

string list[100001];
int n;

int f(int cnt, int c, int s, int e) {
	if(s>e) return 0;
	if(list[s].size()<c) return cnt-1+f(cnt,c,s+1,e);
	if(s==e) return cnt==0?1:cnt;

	bool ok=true;
	for(int i=s+1;i<=e;i++) {
		if(c>=list[i].size() || list[i][c]!=list[s][c]) {
			ok=false; break;
		}
	}
	if(ok) return f(c==0?1:cnt,c+1,s,e);
	
	int res=0;
	int cur=s;
	while(cur<=e) {
		while(cur<e && c<list[cur].size() && c<list[cur+1].size() &&
			list[cur][c]==list[cur+1][c]) cur++;
		res+=f(cnt+1,c+1,s,cur);
		cur++; s=cur;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while(cin>>n) {
		for(int i=0;i<n;i++)
			cin>>list[i];
		if(n==0) { puts("1.00"); continue; }
		sort(list,list+n);
		printf("%.2f\n",1.0*f(0,0,0,n-1)/n);
	}
}