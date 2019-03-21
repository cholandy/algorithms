#include <cstdio>
#include <algorithm>

using namespace std;

char a[22];

int main() {
    int i, n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", a);
        for (i = 0; a[i]; i++);
        sort(a, a + i);
        do {
            puts(a);
        } while(next_permutation(a, a + i));
    }
}