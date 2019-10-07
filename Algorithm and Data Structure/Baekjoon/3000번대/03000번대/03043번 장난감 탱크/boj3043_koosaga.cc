#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;
pi a[505];
vector<pi> vx, vy;
vector<pair<int, char>> ret;

void move(vector<pi> &v, char l, char r){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].first-i-1; j++){
			ret.push_back(pi(v[i].second, l));
		}
	}
	for(int i=v.size()-1; i>=0; i--){
		for(int j=0; j<i+1-v[i].first;j++){
			ret.push_back(pi(v[i].second, r)); 
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		vx.push_back(pi(a[i].first,i+1));
		vy.push_back(pi(a[i].second,i+1));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	int s = 0, e = n-1;
	move(vx, 'U', 'D');
	move(vy, 'L', 'R');
	printf("%d\n",ret.size());
	for(auto &i : ret){
		printf("%d %c\n",i.first, i.second);
	}
}