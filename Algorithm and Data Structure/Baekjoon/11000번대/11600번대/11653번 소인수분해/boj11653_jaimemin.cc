#include <iostream>

#include <vector>

using namespace std;

 

const int MAX = 10000000 + 1;

 

int minFactor[MAX];

vector<int> prime;

 

void eratosthenes(void)

{

        minFactor[0] = minFactor[1] = -1;

        for (int i = 2; i < MAX; i++)

                 minFactor[i] = i;

 

        for (int i = 2; i*i < MAX; i++)

                 if (minFactor[i] == i)

                         for (int j = i * i; j < MAX; j += i)

                                 if (minFactor[j] == j)

                                          minFactor[j] = i;

 

        for (int i = 2; i < MAX; i++)

                 if (minFactor[i] == i)

                         prime.push_back(i);

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int N;

        cin >> N;

       

        eratosthenes();

        for (int i = 0; i < prime.size(); i++)

        {

                 while (!(N%prime[i]))

                 {

                         cout << prime[i] << "\n";

                         N /= prime[i];

                         if (N == 1)

                                 break;

                 }

                 if (N == 1)

                         break;

        }

        return 0;

}