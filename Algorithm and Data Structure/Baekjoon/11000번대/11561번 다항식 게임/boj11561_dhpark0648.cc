//
//  01.cpp
//  BaekJoon
//
//  Created by dhpark on 5/25/18.
//  Copyright © 2018 dhpark. All rights reserved.
//
//  징검다리

#include <cstdio>
#include <cmath>

typedef long long lld;

int t;
lld n;

lld sum(lld);

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    lld i = sqrt(2*n)-1;
    while (n >= sum(++i)) {}
    printf("%lld\n", i-1);
  }
  return 0;
}

lld sum(lld n) {
  return (n * (n+1)) / 2;
}
