#include <iostream>
#include <cstdio>
 
using namespace std;
 
bool arr[52][52];
bool ans[52][52];
 
int n, m;
bool flip(int a, int b)
{
    if (a + 3 > n || b + 3 > m)
        return false;
 
    for (int i = a; i < a + 3; i++)
        for (int j = b; j < b + 3; j++)
            arr[i][j] = !arr[i][j];
 
    return true;
}
 
int main()
{
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &arr[i][j]);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &ans[i][j]);
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] != ans[i][j]) // 서로 값이 다르다면
            {
                if (flip(i, j)) // 뒤집기마다 시도 횟수 + 1
                    cnt++;
                else // 뒤집을 수 없다면 -1
                {
                    printf("-1");
                    return 0;
                }
            }
 
    printf("%d", cnt);
 
    return 0;
}