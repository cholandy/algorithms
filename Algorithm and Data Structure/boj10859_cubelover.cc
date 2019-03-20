#include <cstdio>
#include <cmath>

long long e(long long x, long long y, long long z) {
	long long r = 0;
	while (x) {
		if (x & 1) {
			r += y;
			r %= z;
		}
		x >>= 1;
		y <<= 1;
		y %= z;
	}
	return r;
}

long long f(long long x, long long y, long long z) {
	return y & 1 ? e(f(x, y ^ 1, z), x, z) : y ? f(e(x, x, z), y >> 1, z) : 1;
}

bool isprime(long long n) {
	if (n < 2) return false;
	long long i;
	for (i = 2; i < 1000 && i < n; i++) if (f(i, n - 1, n) != 1) return false;
	return true;
}

int main() {
	long long n, m;
	scanf("%lld", &n);
	if (!isprime(n)) {
		puts("no");
		return 0;
	}
	m = 0;
	while (n) {
		int t = n % 10;
		n /= 10;
		m *= 10;
		if (t == 1 || t == 2 || t == 5 || t == 8) m += t;
		if (t == 6 || t == 9) m += 15 - t;
		if (t == 3 || t == 4 || t == 7) {
			puts("no");
			return 0;
		}
	}
	puts(isprime(m) ? "yes" : "no");
	return 0;
}