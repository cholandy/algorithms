#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int n;
struct x{
	int nai, num;
	string s;
}a[500005];

bool cmp(x a, x b){
	return pi(a.nai, a.num) < pi(b.nai, b.num);
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		char stt[1005];
		scanf("%d %s",&a[i].nai, stt);
		a[i].s = stt;
		a[i].num = i;
	}
	sort(a,a+n,cmp);
	for(int i=0; i<n; i++){
		printf("%d %s\n",a[i].nai,a[i].s.c_str());
	}
}