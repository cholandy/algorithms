#include <iostream>
#include <cstring> //memset

using namespace std;

const int MAX = 300 + 1;

int arr[MAX][MAX];
int cache[MAX][MAX];
int N, M;
int i, j, x, y;

int arrSum(void)
{
        cin >> i >> j >> x >> y;
        if (i > x || j > y)
               exit(-1);
        return cache[x][y] - cache[i - 1][y] - cache[x][j - 1] + cache[i- 1][j - 1];
}

 

int main(void)

{

        memset(arr, 0, sizeof(arr));
        memset(cache, 0, sizeof(cache));
        cin >> N >> M;
        if (N < 1 || N >= MAX || M < 1 || M >= MAX)
               exit(-1);
        for (int i = 1; i <= N; i++)
               for (int j = 1; j <= M; j++)
                       cin >> arr[i][j];
        for(int i=1; i<=N; i++)
               for (int j = 1; j <= M; j++)
               {
                       cache[i][j] = arr[i][j];
                       cache[i][j] += (cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1]);
               }
        int K; //합을 구할 부분의 개수
        cin >> K;
        if (K < 1 || K>10000)
 
             exit(-1);

       

        for (int idx = 0; idx < K; idx++)

               cout << arrSum() << endl;

        return 0;

}