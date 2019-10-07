#include <cstdio>

#include <queue>

#include <algorithm>

using namespace std;

typedef pair<int, int> MP;

typedef pair<MP, int> MT;

#define mp(a,b) make_pair(a,b)

#define mt(a,b,c) mp(mp(a,b),c)

struct Bird{

    int y, x, info;

    int skill, cnt;

    Bird(int yy, int xx, int ii, int ss, int cc) :y(yy), x(xx), info(ii), skill(ss), cnt(cc){}

};

bool operator<(const Bird a, const Bird b){

    return a.cnt > b.cnt;

    

}

int N, M, C;

bool visit[1001][1001];

char map[1001][1001];


int bfs(Bird &bird){

    int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, 1, -1, 0 };

    priority_queue <Bird> pq;

    queue<Bird> q;


    pq.push(bird);

    while (!pq.empty()){

        Bird b = pq.top();

        pq.pop();


        if (b.info == (1 << C) - 1) return b.cnt;

        for (int n = 0; n < N; n++)

            for (int m = 0; m < M; m++)

                visit[n][m] = false;


        q.push(b);

        visit[b.y][b.x] = true;


        while (!q.empty()){

            Bird here = q.front();

            q.pop();


            for (int i = 0; i < 4; i++){

                int y = here.y + dy[i], x = here.x + dx[i];

                Bird next = Bird(y, x, here.info, here.skill, here.cnt + 1);


                if (y < 0 || y >= N || x < 0 || x >= M || visit[y][x] || map[y][x] == 'X') continue;


                if (map[y][x] == '.'){

                    q.push(next);

                    visit[y][x] = true;

                }

                else{

                    int cheeze = map[y][x] - '0';

                    if (here.skill >= cheeze){        //치즈를 얻을 수 있다면

                        if ((here.info & (1 << (cheeze - 1))) > 0){            //이미 먹은 치즈라면

                            q.push(next);                //지나감

                            visit[y][x] = true;    

                        }

                        else{

                            visit[y][x] = true;

                            pq.push(Bird(y, x, here.info | (1 << (cheeze - 1)), here.skill + 1, here.cnt + 1));

                        }

                    }

                    else{                            //못얻는다면

                        q.push(next);

                        visit[y][x] = true;                //지나감

                    }

                }

            }

        }

    }

    

    return -1;

}

int main(){

    Bird bird(0, 0, 0, 1, 0);

    scanf("%d%d%d", &N, &M, &C);

    for (int n = 0; n < N; n++){

        for (int m = 0; m < M; m++){

            scanf(" %1c", &map[n][m]);

            if (map[n][m] == 'S') bird.y = n, bird.x = m;

        }

    }


    printf("%d\n",bfs(bird));

    return 0;

}
