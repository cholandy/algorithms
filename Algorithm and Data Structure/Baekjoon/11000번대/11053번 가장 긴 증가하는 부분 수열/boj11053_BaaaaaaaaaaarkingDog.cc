#include <bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  d[0] = 1;
  for(int i = 1; i < n; i++){
    d[i] = 1;
    for(int j = 0; j < i; j++)
      if(a[j] < a[i]) d[i] = max(d[i], d[j]+1); 
      // a[i]보다 작은 원소여야 a[i]의 앞에 쓸 수 있으므로
  }
  cout << *max_element(d,d+n);
}