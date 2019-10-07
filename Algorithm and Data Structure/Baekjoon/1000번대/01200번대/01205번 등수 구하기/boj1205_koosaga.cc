#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n, p, q;

int main(){
	cin >> n >> p >> q;
	int cnt = 0, rnk = 0;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x >= p) cnt++;
		if(x > p) rnk++;
	}
	if(cnt + 1 <= q){
		printf("%d\n", rnk + 1);
	}
	else puts("-1");
}
