#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int g(int x, int y){ return y ? g(y, x%y) : x; }

int main(){
	int n, m;
	scanf("%d:%d",&n,&m);
	printf("%d:%d",n/g(n,m), m/g(n,m));
}
