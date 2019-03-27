#include <iostream>

#include <string>

#include <algorithm>

using namespace std;

 

const int INF = 987654321;

 

typedef struct

{

        int y, x;

}Dir;

 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

 

int o, result;

string board[5];

 

void DFS(int cnt, string s[5])

{

        bool flag = false;

        string copyBoard[5];

 

        for (int j = 0; j < 5; j++)

        {

                 for (int k = 0; k < 9; k++)

                 {

                         //o이고

                         if (s[j][k] == 'o')

                         {

                                 for (int i = 0; i < 4; i++)

                                 {

                                          int nextY = j + moveDir[i].y;

                                          int nextX = k + moveDir[i].x;

                                          int nextYY = j + 2 * moveDir[i].y;

                                          int nextXX = k + 2 * moveDir[i].x;

 

                                          //인접한 칸도 o이고 인접한 칸의 다음칸은 비어있다면

                                          if (0 <= nextYY && nextYY < 5 && 0 <= nextXX && nextXX < 9)

                                                  if (s[nextY][nextX] == 'o' && s[nextYY][nextXX] == '.')

                                                  {

                                                          flag = true;

                                                          for (int l = 0; l < 5; l++)

                                                                   copyBoard[l] = s[l];

                                                          copyBoard[j][k] = '.';

                                                          copyBoard[nextY][nextX] = '.';

                                                          copyBoard[nextYY][nextXX] = 'o';

                                                          DFS(cnt + 1, copyBoard);

                                                  }

                                 }

                         }

                 }

        }

 

        //o를 하나도 못 움직였다면 더 이상 진행 불가

        if (!flag)

        {

                 int num = 0;

                 for (int i = 0; i < 5; i++)

                         for (int j = 0; j < 9; j++)

                                 if (s[i][j] == 'o')

                                          num++;

 

                 if (o > num) //o의 개수를 업데이트하며 횟수도 업데이트

                 {

                         o = num;

                         result = cnt;

                 }

                 //o의 개수는 같지만 횟수가 더 적을 때 최소 횟수 업데이트

                 else if (o == num && result > cnt)

                         result = cnt;

        }

        return;

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int N;

        cin >> N;

 

        for (int t = 0; t < N; t++)

        {

                 for (int i = 0; i < 5; i++)

                         cin >> board[i];

 

                 o = INF;

                 DFS(0, board);

                 cout << o << " " << result << "\n";

        }

        return 0;

}