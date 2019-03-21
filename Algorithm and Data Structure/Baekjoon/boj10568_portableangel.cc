#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

typedef long long lli;

double f[60][60];
lli x[60], y[60], z[60];
map<string,int> d;

int main() {
	int t, p, m, q;
	string u, v;
	cin>>t;
	for(int tc=1;tc<=t;tc++) {
		printf("Case %d:\n",tc);
		d.clear();
		cin>>p;
		for(int i=0;i<p;i++) {
			for(int j=0;j<p;j++) {
				if(i!=j) f[i][j]=1e9;
				else f[i][j]=0.0;
			}
		}
		for(int i=0;i<p;i++) {
			cin>>u>>x[i]>>y[i]>>z[i];
			d[u]=i;
		}
		for(int i=0;i<p;i++) {
			for(int j=0;j<p;j++) if(i!=j) {
				f[i][j]=sqrt(1.0*((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])));
			}
		}
		cin>>m;
		while(m--) {
			cin>>u>>v;
			f[d[u]][d[v]]=0.0;
		}
		for(int k=0;k<p;k++) {
			for(int i=0;i<p;i++) {
				for(int j=0;j<p;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
		cin>>q;
		while(q--) {
			cin>>u>>v;
			printf("The distance from %s to %s is %.0f parsecs.\n",u.c_str(),v.c_str(),f[d[u]][d[v]]+1e-9);
		}
	}
}