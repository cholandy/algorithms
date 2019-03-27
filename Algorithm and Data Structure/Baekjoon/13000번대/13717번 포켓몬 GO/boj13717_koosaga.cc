#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int query(int x, int y){
	int ret = 0;
	while(y >= x){
		y -= x;
		y += 2;
		ret++;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	int mx = -1, sum = 0;
	string ret;
	while(n--){
		string s;
		int a, b;
		cin >> s >> a >> b;
		int w = query(a, b);
		sum += w;
		if(mx < w){
			mx = w;
			ret = s;
		}
	}
	cout << sum << endl << ret;
}
