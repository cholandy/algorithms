#include <bits/stdc++.h>
using namespace std;
int N, r, g, b, R, G, B;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &r, &g, &b);
		r += min(G, B); g += min(R, B); b += min(R, G);
		R = r; G = g; B = b;
	}
	printf("%d", min(min(R, G), B));
	return 0;
}