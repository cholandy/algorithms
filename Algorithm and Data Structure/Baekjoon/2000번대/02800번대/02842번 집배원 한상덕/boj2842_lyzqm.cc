#include <cstdio>

#include <queue>

#include <vector>

#include <functional>

#include <algorithm>

#define INF 987654321

using namespace std;

typedef pair<int, int> P;

int N;

char map[51][51];

int tire[51][51];

vector<int> vec;

int di(int sy,int sx, int small){

    int dy[8] = { -1, 0, 0, 1, -1, -1, 1, 1 }, dx[8] = { 0, 1, -1, 0, 1, -1, 1, -1 };

    int visit[51][51] = { 0 };

    priority_queue<P,vector<P>, greater<P> > pq;


    int ans = 0;

    pq.push({tire[sy][sx] ,sy * N + sx});

    while (!pq.empty()){

        int dist = pq.top().first;

        int y = pq.top().second / N, x = pq.top().second % N;

        if (map[y][x] == 'K')

            ans = max(ans, dist);

        pq.pop();


        if (visit[y][x]) continue;

        visit[y][x] = 1;


        for (int i = 0; i < 8; i++){

            int ny = y + dy[i], nx = x + dx[i];

            int next;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (!visit[ny][nx] && tire[ny][nx] >= small){

                next = max(tire[ny][nx], dist);

                pq.push(make_pair(next, ny*N + nx));

            }

        }

    }


    for (int n = 0; n < N; n++){

        for (int m = 0; m < N; m++){

            if (map[n][m] == 'K' && visit[n][m] == 0)

                return INF;

        }

    }

    return ans;

}

int main(){

    int sy, sx;

    scanf("%d", &N);

    for (int n = 0; n < N; n++)

        scanf("%s", map[n]);


    for (int n = 0; n < N; n++){

        for (int m = 0; m < N; m++){

            scanf("%d", &tire[n][m]);

            vec.push_back(tire[n][m]);

            if (map[n][m] == 'P'){

                sy = n;

                sx = m;

            }

        }

    }

    sort(vec.begin(), vec.end());

    vec.erase(unique(vec.begin(), vec.end()), vec.end());


    int ans = INF;

    for (int i = 0; i < vec.size() && vec[i] <= tire[sy][sx]; i++)

        ans = min(ans, di(sy, sx, vec[i]) - vec[i]);

    printf("%d\n", ans);

    return 0;

}
