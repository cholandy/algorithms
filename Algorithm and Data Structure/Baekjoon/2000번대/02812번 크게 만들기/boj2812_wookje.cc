#include <cstdio>

int n, k, pos;
char s[500005];

int main() {
    scanf("%d %d %c", &n, &k, &s[0]);
    pos = 1;
    for (int i = 1; i < n; i++) {
        scanf("%c", &s[pos]);
        while (k && pos && s[pos-1] < s[pos]) {
            s[pos-1] = s[pos];
            s[pos] = 0;
            k--;
            pos--;
        }
        pos++;
    }

    while (k--) {
        s[--pos] = 0;
    }

    puts(s);

    return 0;
}