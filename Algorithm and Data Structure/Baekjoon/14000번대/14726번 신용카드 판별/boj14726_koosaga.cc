#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
typedef long long lint;

int main(){
	priority_queue<double> pq;
	int n;
	scanf("%d",&n);
	while(n--){
		string x;
		cin >> x;
		for(int i=x.size()-2; i>=0; i-=2){
			int w = x[i] - '0';
			w *= 2;
			while(w >= 10) w = (w % 10) + 1;
			x[i] = w + '0';
		}
		int ret = 0;
		for(auto &i : x) ret += i - '0';
		puts(ret % 10 ? "F" : "T");
	}
}
