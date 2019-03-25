#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
 
bool prime[1000002];
vector<int> test;
int m, sqm, t, i, j;
 
int main(void) {
    while (1) {
        scanf("%d", &t);
        if (t == 0)
            break;
        test.push_back(t);
        m < t ? m = t : 0;
    }
    sqm = sqrt(m);
    for (i = 2; i <= m; ++i) {
        if (prime[i] == false)
            for (j = 2; i * j <= m; ++j)
                prime[i*j] = true;
    }
    int s = test.size();
    for (i = 0; i < s; ++i) {
        for (j = test[i] - 3; ; --j) {
            if (prime[j] == false) {
                if (prime[test[i] - j] == false) {
                    printf("%d = %d + %d\n", test[i], test[i] - j, j);
                    break;
                }
            }
        }
    }
    return 0;
}
