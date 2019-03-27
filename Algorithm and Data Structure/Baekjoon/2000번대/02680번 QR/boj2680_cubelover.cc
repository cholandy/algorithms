#include <cstdio>

char a[44];
int n;

char r[256], *p;
int m;

char s[55] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

int g(int x) {
	return x < 10 ? x | 48 : x + 55;
}

int get() {
	int t = a[n >> 2];
	if (t & 64) t -= 55;
	t = t >> 3 - (n & 3) & 1;
	n++;
	return t;
}

int getNum(int cnt) {
	int i, a = 0;
	for (i = 0; i < cnt; i++) a = a << 1 | get();
	return a;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int i, t;
		bool f = true;
		scanf("%s", a);
		n = m = 0;
		p = r;
		while (f) {
			switch (getNum(4)) {
			case 0:
				f = false;
				break;
			case 1:
				t = getNum(10);
				m += t;
				for (i = 0; i < t / 3; i++) {
					int x = getNum(10);
					*p++ = x / 100 | 48;
					*p++ = x / 10 % 10 | 48;
					*p++ = x % 10 | 48;
				}
				if (t % 3 == 1) *p++ = getNum(4) | 48;
				if (t % 3 == 2) {
					int x = getNum(7);
					*p++ = x / 10 | 48;
					*p++ = x % 10 | 48;
				}
				break;
			case 2:
				t = getNum(9);
				m += t;
				for (i = 0; i < t / 2; i++) {
					int x = getNum(11);
					*p++ = s[x / 45];
					*p++ = s[x % 45];
				}
				if (t % 2) *p++ = s[getNum(6)];
				break;
			case 4:
				t = getNum(8);
				m += t;
				for (i = 0; i < t; i++) {
					int x = getNum(8);
					if (x >= 32 && x <= 126) {
						if (x == '\\' || x == '#') *p++ = '\\';
						*p++ = x;
					}
					else {
						*p++ = '\\';
						*p++ = g(x >> 4);
						*p++ = g(x & 15);
					}
				}
				break;
			case 8:
				t = getNum(8);
				m += t;
				for (i = 0; i < t; i++) {
					int x = getNum(13);
					*p++ = '#';
					*p++ = g(x >> 12);
					*p++ = g(x >> 8 & 15);
					*p++ = g(x >> 4 & 15);
					*p++ = g(x & 15);
				}
				break;
			}
		}
		*p = 0;
		printf("%d %s\n", m, r);
	}
	return 0;
}
