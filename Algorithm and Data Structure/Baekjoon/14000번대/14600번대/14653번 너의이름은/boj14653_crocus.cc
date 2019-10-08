#include <iostream>
#include <cstdio>
 
using namespace std;
 
pair<int, char> msg[10005];
 
bool chk[200];
int main()
{
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
 
    for (int i = 0; i < k; i++)
        scanf("%d %c", &msg[i].first, &msg[i].second);
 
    // A는 무조건 읽는다.
    chk['A'] = true;
 
    // 이전에 메시지를 보낸 사람의 읽은 수와 현재 q의 읽은수가 동일하면
    for (int i = 0; i < k; i++)
    {
        if (msg[i].first == msg[q - 1].first)
            chk[msg[i].second] = true;
    }
 
    // 현재 메시지 이후로 모든 보낸 사람들 true
    for (int i = q - 1; i < k; i++)
        chk[msg[i].second] = true;
 
    // 현재 메시지를 모두 읽었다면
    if (msg[q-1].first == 0)
        printf("-1");
 
    else
        for (int i = 'A'; i <= 'A' + n - 1; i++)
            if (!chk[i])
                printf("%c ", i);
 
    return 0;
}
