#include<cstdio>
#include<queue>
#pragma warning(disable :4996)
using namespace std;
 
struct Data {
    int a, b, c;
};
 
//대문자 A,B,C 는 각 물통에 담을 수 있는 물의 최대용량
//now.a,now.b,now.c 는 현재 물통에 담아져 있는 물의 용량
//chk[a의 물의 양][b의 물의 양]
 
int A, B, C;
bool chk[202][202],ans[202];
 
void bfs()
{
    queue <Data> q;
    q.push({0,0,C});
 
    while (!q.empty())
    {
        Data now = q.front();
        q.pop();
 
        //이미 확인한 무게라면 다음 것 확인
        if (chk[now.a][now.b])
            continue;
 
        chk[now.a][now.b] = true;
 
        //첫 번째 물통이 비어 있을 때, 세번째 물통에 담겨 있을 수 있는 물의 양
        //배열의 index로 무게 체크
        if (now.a == 0)
            ans[now.c] = true;
 
        //a->b
        //현재 a에 담겨있는 양 + 현재 b에 담겨있는 양이
        //입력값 B(최대용량)보다 큰 경우 B물통은 최대용량만큼
        //물이 가득채워지게 되고, A물통은 현재 a양 + 현재 b양 - 최대용량만큼
        //물이 남게 된다.
        if (now.a + now.b > B)
            q.push({ (now.a + now.b) - B,B,now.c });
 
        //현재 a + 현재 b 용량이 B(최대용량)보다 작은 경우
        //A물통에서 물이 전부 옮겨지므로 A는 0
        //B는 현재 a + 현재 b 용량이 된다.
        //C는 변화가 없으므로 현재 용량 now.c를 넣어준다.
        else
            q.push({0,now.a+now.b,now.c});
 
        //a->c
        if (now.a + now.c > C)
            q.push({ (now.a + now.b) - C,now.b,C });
        else
            q.push({0,now.b,now.a+now.c});
 
        //b->a
        if (now.b + now.a > A)
            q.push({ A,(now.b + now.a) - A,now.c });
        else
            q.push({now.b+now.a, 0, now.c});
 
        //b->c
        if (now.b + now.c > C)
            q.push({ now.a,(now.b + now.c) - C,C });
        else
            q.push({now.a, 0, now.b+now.c});
 
        //c->a
        if (now.c + now.a > A)
            q.push({ A,now.b,(now.c + now.a) - A });
        else
            q.push({now.c+now.a,now.b,0});
 
        //c->b
        if (now.c + now.b > B)
            q.push({ now.a,B,(now.c + now.b) - B });
        else
            q.push({now.a,now.c+now.b,0});
    }
}
 
void print()
{
    for (int i = 0; i <= C; i++)
    {
        if (ans[i])
            printf("%d ", i);
    }
}
 
int main(void)
{    
    scanf("%d %d %d", &A, &B, &C);
    bfs();
    print();
    return 0;
}
