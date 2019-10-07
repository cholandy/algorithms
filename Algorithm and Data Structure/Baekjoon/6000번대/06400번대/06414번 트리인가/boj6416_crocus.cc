#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
 
using namespace std;
 
int indegree[10002];
int outdegree[10002];
bool nodeChk[10002];
 
int main()
{
    int tc = 1;
    int edge = 0;
    int maxNode = -1;
    int minNode = 987654321;
    int root = -1;
 
    bool chk = true;
    while (tc)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        nodeChk[a] = nodeChk[b] = true;
 
        if (a == -1 && b == -1)
            break;
 
        if(a != 0 && b != 0)
        {
            maxNode = max({ maxNode, a,b });
            minNode = min({ minNode, a,b });
        }
        if (!a && !b)
        {
            // root노드 찾는과정, 이때 루트 2번발견되면 트리 x
            for (int i = minNode; i <= maxNode; i++)
            {
                if (indegree[i] == 0 && outdegree[i] != 0)
                {
                    if (root != -1)
                        chk = false;
                    
                    root = i;
                }
            }
 
            // 트리 정의 :: 진입차수 2개이상되는게 발견되면 트리 x
            for (int i = minNode; i <= maxNode; i++)
                if (indegree[i] >= 2)
                    chk = false;
                
            // 노드 개수 카운트
            int get = 0;
            for (int i = minNode; i <= maxNode; i++)
                if (nodeChk[i])
                    get++;
                
            // 트리 정의 :: 엣지 + 1 == 노드
            if (edge + 1 != get)
                chk = false;
            
            // 트리 정의 :: 루트가 존재해야 한다.
            if (root == -1)
                chk = false;
            
 
            if (chk || !edge)
                printf("Case %d is a tree.\n", tc++);
            else
                printf("Case %d is not a tree.\n", tc++);
 
            memset(indegree, 0, sizeof(indegree));
            memset(outdegree, 0, sizeof(outdegree));
            memset(nodeChk, false, sizeof(nodeChk));
 
            root = -1;
            edge = 0;
            maxNode = -1;
            minNode = 987654321;
            chk = true;
            continue;
        }
 
        indegree[b]++;
        outdegree[a]++;
        edge++;
    }
 
    return 0;
}
