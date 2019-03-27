#include <iostream>

#include <vector>

#include <queue>

using namespace std;

 

const int MAX = 1000 + 1;

 

int N, M;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0); //cin 실행속도 향상

        int T;

        cin >> T;

 

        while (T--)

        {

                 cin >> N >> M;

 

                 for (int i = 0; i < M; i++)

                 {

                         int node1, node2;

                         cin >> node1 >> node2;

                 }

                 //MST는 N-1개의 간선으로 이루어져있다

                 cout << N - 1 << "\n";

        }

        return 0;

}