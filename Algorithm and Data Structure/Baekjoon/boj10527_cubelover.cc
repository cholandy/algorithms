#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string, int> M;
char t[16];

int main() {
	int i, n, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", t);
		M[t]++;
	}
	for (i = 0; i < n; i++) {
		scanf("%s", t);
		if (M[t]) {
			r++;
			M[t]--;
		}
	}
	printf("%d", r);
}