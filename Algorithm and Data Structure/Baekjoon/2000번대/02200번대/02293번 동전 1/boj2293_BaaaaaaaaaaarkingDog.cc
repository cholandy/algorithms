#include <bits/stdc++.h>
using namespace std;

int a[105];
int n,k;
vector<int> d1;
vector<int> d2; // 배열보다 vector가 값의 복사가 편함

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  d1.resize(k+1);
  d2.resize(k+1);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int t = 0; t <= k; t += a[0]) d1[t] = 1; // k 이하의 a[0]의 배수들에 대해 모두 경우의 수가 1가지 있음을 명시
  for(int i = 1; i < n; i++){
    fill(d2.begin(),d2.end(),0); // d2를 0으로 초기화
    for(int j = 0; j <= k; j++){            
      d2[j] = d1[j];
      if(j >= a[i]) d2[j] += d2[j-a[i]];
    }
    d1 = d2; // d1으로 d[i][..]을 옮김. 만약 배열로 하고 싶으면 그냥 for문 한번 돌면서 값을 옮기면 됨
  }
  cout << d1[k];
}