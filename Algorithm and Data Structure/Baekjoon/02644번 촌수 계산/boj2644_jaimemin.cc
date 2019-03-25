#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

using namespace std;

 

const int MAX = 100 + 1;

 

int N, M;

int node1, node2; //촌수 계산하는 두 사람

vector<int> family[MAX];

int cache[MAX];

 

//전형적인 BFS

int BFS(void)

{

        queue<int> q;

        q.push(node1);

       

        while (!q.empty())

        {

                 int currentNode = q.front();

                 q.pop();

 

                 if (currentNode == node2)

                         return cache[node2];

 

                 for (int i = 0; i < family[currentNode].size(); i++)

                 {

                         int next = family[currentNode][i];

                         //서로 촌수가 정해져있지 않았을 경우에만 update

                         if (cache[next] == 0)

                         {

                                 q.push(next);

                                 cache[next] = cache[currentNode] + 1;

                         }

                 }

        }

        return -1;

}

 

int main(void)

{

        cin >> N;

 

        cin >> node1 >> node2;

       

        cin >> M;

        for (int i = 0; i < M; i++)

        {

                 int parent, child;

                 cin >> parent >> child;

 

                 family[parent].push_back(child);

                 family[child].push_back(parent);

        }

 

        cout << BFS() << endl;

 

        return 0;

}