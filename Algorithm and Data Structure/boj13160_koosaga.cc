#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n;
pi a[300005];
map<int, int> mp;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first, &a[i].second);
		mp[2*a[i].first]++;
		mp[2*a[i].second+1]--;
	}
	int pos = -1, cur = 0, hap = -1;
	for(auto &i : mp){
		cur += i.second;
		if(cur > hap){
			hap = cur;
			pos = i.first / 2;
		}
	}
	printf("%d\n", hap);
	for(int i=0; i<n; i++){
		if(a[i].first <= pos && a[i].second >= pos){
			printf("%d ", i+1);
		}
	}
}
	

