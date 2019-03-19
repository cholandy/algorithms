#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

string s, t;
string r;

int main(){
	cin >> s >> t;
	for(auto &i : s){
		r.push_back(i);
		if(r.size() >= t.size() && r.substr(r.size()-t.size(), t.size()) == t){
			for(int j=0; j<t.size(); j++) r.pop_back();
		}
	}
	if(r.empty()) r = "FRULA";
	cout << r;
}