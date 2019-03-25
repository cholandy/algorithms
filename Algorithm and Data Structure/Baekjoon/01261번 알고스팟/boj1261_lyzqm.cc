#include <cstdio>

#include <queue>

#include <vector>

#include <functional>

#define INF 987654321

using namespace std;

typedef pair<int, int> P;

int N, M;

char map[101][101];

int bfs(){

    int dist[101][101];

    int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };

    priority_queue<P, vector<P>, greater<P>> pq;


    for (int n = 0; n < N; n++)

        for (int m = 0; m < M; m++)

            dist[n][m] = INF;

    pq.push({ 0, 0 });

    dist[0][0] = 0;

    while (!pq.empty()){

        int block = pq.top().first;

        int y = pq.top().second / M, x = pq.top().second % M;

        pq.pop();


        for (int i = 0; i < 4; i++){

            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (map[ny][nx] == '1'){

                if (dist[ny][nx] > block + 1){

                    dist[ny][nx] = block + 1;

                    pq.push({ block + 1, ny*M + nx });

                }

            }

            else{

                if (dist[ny][nx] > block){

                    dist[ny][nx] = block;

                    pq.push({ block, ny*M + nx });

                }

            }

        }

    }

    return dist[N - 1][M - 1];

}

int main(){

    scanf("%d%d", &M, &N);

    for (int n = 0; n < N; n++)

        scanf("%s", map[n]);

    printf("%d\n", bfs());

    return 0;

}
