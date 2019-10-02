#include <stdio.h>

#define MAX 1001001

using namespace std;

int N;
bool check[MAX] = {false,};
int ans=0;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        bool flag = true;
        for (int j = 0; j < 3; ++j) {
            int num;
            scanf("%d", &num);
            if (check[num]) flag = false;
            else check[num] = true;
        }
        if (flag) ans++;
    }
    printf("%d\n", ans);
}