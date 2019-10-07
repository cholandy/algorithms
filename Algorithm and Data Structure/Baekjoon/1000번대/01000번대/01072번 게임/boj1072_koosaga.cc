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
#include <list>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int x, y;
int main(){
	while(~scanf("%d %d",&x,&y)){
		int oz = (100ll * y) / x + 1;
		lint s = 0, e = 1e15;
		while(s != e){
			lint m = (s+e)/2;
			if((100ll * (y + m)) / (x + m) >= oz){
				e = m;
			}
			else s = m+1;
		}
		if(s > 1e14) s = -1;
		printf("%lld\n", s);
	}
}