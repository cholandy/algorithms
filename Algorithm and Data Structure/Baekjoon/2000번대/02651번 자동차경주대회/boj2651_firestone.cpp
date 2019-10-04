#include <stdio.h>
#include <malloc.h>

using namespace std;

int distance, stop_cnt;
int stops[101] = {0,};
int times[100] = {0,};

int main() {
    scanf("%d", &distance);
    scanf("%d", &stop_cnt);

    for (int i=0;i<stop_cnt+1;i++) {
        scanf("%d", &stops[i]);
    }
    for (int i=0; i<stop_cnt;i++) {
        scanf("%d", &times[i]);
    }

    int dp[101];
    

    return 0;
}