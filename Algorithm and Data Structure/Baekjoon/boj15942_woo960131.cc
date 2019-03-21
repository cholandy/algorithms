#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <map>

#define si(n) fscanf(stdin, "%d", &n)

using namespace std;

int N, k, p, cntP, cntC, idx[4];
int Type[210000]; // 0 : default, 1 : parent, 2 : child, 3 : itself

int countParent(int n, int pos) {
  int ret = 0;
  while(pos != 0) {
    Type[pos] = 1;
    pos /= 2;
    ret++;
  }
  return ret - 1;
}

int countChild(int n, int pos) {
  int ret = 0, width = 1;
  while (pos <= n) {
    if (pos + width - 1 <= n) {
      ret += width;
      for (int i = 0; i < width; i++) Type[pos + i] = 2;
    }
    else {
      ret += (n - pos + 1);
      for (int i = 0; i <= n - pos; i++) Type[pos + i] = 2;
    }
    pos *= 2;
    width *= 2;
  }
  return ret - 1;
}

int main() {
  si(N), si(k), si(p);

  for (int i = 1; i <= N; i++) idx[i] = 0;

  if ((cntP = countParent(N, p)) >= k) {
    printf("-1\n");
    return 0;
  }

  if ((cntC = countChild(N, p)) >= N - k + 1) {
    printf("-1\n");
    return 0;
  }

  Type[p] = 3;
  idx[0] = cntP + 1, idx[1] = 1, idx[2] = N - cntC + 1, idx[3] = k;
  if (idx[0] == k) idx[0]++;

  for (int i = 1; i <= N; i++) {
    printf("%d\n", idx[Type[i]]);
    idx[Type[i]]++;
    if (idx[Type[i]] == k) idx[Type[i]]++;
  }
}
