#include <cstdio>
using namespace std;
 
int main(){
    // use[i]: i번 구에 꽂혀있는 전기용품의 번호
    // plan[i]: i번째로 사용할 전기용품의 번호
    int N, K, use[100] = {0}, plan[100];
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++)
        scanf("%d", plan+i);
 
    int result = 0;
    for(int i=0; i<K; i++){
        // 먼저 해당 전기용품이 이미 꽂혀 있는지 확인
        bool inUse = false;
        for(int j=0; j<N; j++)
            if(plan[i] == use[j]){
                inUse = true;
                break;
            }
        // 이미 꽂혀 있다면 아무것도 뽑을 필요 없음
        if(inUse) continue;
 
        // 아직 비어 있는 구멍이 있는지 확인
        inUse = false;
        for(int j=0; j<N; j++)
            if(use[j] == 0){
                // 비어 있는 구멍을 발견하면 거기에 꽂음
                use[j] = plan[i];
                inUse = true;
                break;
            }
        // 비어 있는 구멍이 있다면 아무것도 뽑을 필요 없음
        if(inUse) continue;
 
        // 가장 나중에 다시 사용될 전기용품을 찾음
        int swap, val = -1;
        for(int j=0; j<N; j++){
            int term = 0;
            for(int k=i+1; k<K && use[j]!=plan[k]; k++) term++;
            if(term > val){
                swap = j;
                val = term;
            }
        }
        // 플러그를 뽑는 횟수 1 증가
        result++;
        // 해당 구멍에 꽂혀 있는 전기용품이 바뀜
        use[swap] = plan[i];
    }
    printf("%d\n", result);
}

