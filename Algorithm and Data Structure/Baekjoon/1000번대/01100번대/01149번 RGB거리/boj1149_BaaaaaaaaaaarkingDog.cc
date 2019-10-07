#include <bits/stdc++.h>
using namespace std;

int s[1005][3];
int d[1005][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i][0] >> s[i][1] >> s[i][2];
  d[0][0] = s[0][0];
  d[0][1] = s[0][1];
  d[0][2] = s[0][2];
  for(int i = 1; i < n; i++){
    d[i][0] = min(d[i-1][1],d[i-1][2])+s[i][0];
    d[i][1] = min(d[i-1][0],d[i-1][2])+s[i][1];
    d[i][2] = min(d[i-1][0],d[i-1][1])+s[i][2];
  }
  cout << min(min(d[n-1][0],d[n-1][1]),d[n-1][2]); 
  // 내장 min 함수가 2개의 인자를 받는 함수여서 이런 식으로 작성해 3개의 값 중에 최댓값을 뽑을 수 있다.
}