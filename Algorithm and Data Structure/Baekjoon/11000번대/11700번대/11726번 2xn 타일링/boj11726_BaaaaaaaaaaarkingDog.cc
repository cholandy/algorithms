#include <bits/stdc++.h>
using namespace std;

int d[10005];
int mod = 10'007;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  for(int i = 3; i <= n; i++) d[i] = (d[i-1]+d[i-2])%mod; 
  // 계산하는 중간중간 나머지를 취하지 않고 끝나고 나누게 되면 int overflow로 인해 오답이 발생
  cout << d[n];
}