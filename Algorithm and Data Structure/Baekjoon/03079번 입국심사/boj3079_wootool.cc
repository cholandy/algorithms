#include <stdio.h>
 
long long T[1000001];
 
int main(void){
 
    int N, M;
    long long max = 0;
    scanf("%d %d", &N, &M);
 
    for (int i = 0; i < N; i++){
        scanf("%lld", &T[i]);
        if (max < T[i])
            max = T[i];
    }
 
    long long left=1, right=max*M;
    long long result = max*M;
    while (left <= right){
        long long mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < N; i++)
        {
            total += mid / T[i];
        }
 
        if (total < M){
            left = mid + 1;
        }
        else{
            if (result>mid)
                result = mid;
            right = mid - 1;
        }
    }
    printf("%lld\n", result);
 
    return 0;
}
