#include <cstdio>

char s[8];

int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		int n, m, l;
		scanf("%s%d%d%d", s, &n, &m, &l);
		l *= 100000000;
		if (s[2] == '2') {
			if (n > 30) {
				puts("TLE!");
				continue;
			}
			while (n--) l >>= 1;
			puts(l < m ? "TLE!" : "May Pass.");
			continue;
		}
		if (s[3] == '!') {
			if (n > 15) {
				puts("TLE!");
				continue;
			}
			while (n) l /= n--;
			puts(l < m ? "TLE!" : "May Pass.");
			continue;
		}
		if (s[4] == '3') {
			l /= n;
			l /= n;
			l /= n;
			puts(l < m ? "TLE!" : "May Pass.");
			continue;
		}
		if (s[4] == '2') {
			l /= n;
			l /= n;
			puts(l < m ? "TLE!" : "May Pass.");
			continue;
		}
		l /= n;
		puts(l < m ? "TLE!" : "May Pass.");
	}
	return 0;
}