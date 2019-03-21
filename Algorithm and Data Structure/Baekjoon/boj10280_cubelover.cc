#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	puts(m > n / 3 && m <= n - (n + 1) / 3 ? "YES" : "NO");
}