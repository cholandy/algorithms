#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        int cnt = 0;

        for(int i = 1; i * i<= num; i++) {
            if (num % i == 0) {
                cnt++; // 약수 개수
                if (i * i < num) cnt++;
            }
        }
        printf("%d %d\n", num, cnt);
    }
}