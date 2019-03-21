#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, a[100005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	int b, c; cin >> b >> c;
	lint ret = 0;
	for(int i=0; i<n; i++){
		ret++;
		if(a[i] > b) ret += max(0, a[i] - b + c - 1) / c;
	}
	cout << ret;
}
