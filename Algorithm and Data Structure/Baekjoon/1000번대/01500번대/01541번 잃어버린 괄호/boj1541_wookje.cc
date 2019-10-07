#include <cstdio>

int sum, tmp, f, n;
char s[55] = {1};

int main() {
    scanf("%s", s+1);
    for (int i = 1; s[i-1]; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            n *= 10;
            n += s[i] - '0';
        }
        else if (s[i] == '+') {
            tmp += n;
            n = 0;
        }
        else {
            tmp += n;
            n = 0;
            sum += f ? -tmp : tmp;
            tmp = 0;
            f = (s[i] == '-');
        }
    }

    printf("%d ", sum);

    return 0;
}