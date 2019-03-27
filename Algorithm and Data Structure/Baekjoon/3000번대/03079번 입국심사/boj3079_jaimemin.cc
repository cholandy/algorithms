
#include <iostream>

#include <vector>

#include <algorithm>

#include <climits>

using namespace std;

 

const int MAX = 100000;

 

int N, M;

long long arr[MAX];

 

bool func(long long time)

{

        long long temp = 0;

        for (int i = 0; i < N; i++)

                 temp += time / arr[i];

        //조건을 충족?

        return temp >= M;

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> N >> M;

       

        for (int i = 0; i < N; i++)

                 cin >> arr[i];

 

        long long low = 1, high = 1000000000000000000LL;

        long long result = LLONG_MAX;

        while (low <= high)

        {

                 long long mid = (low + high) / 2;

                 if (func(mid))

                 {

                         result = min(result, mid);

                         high = mid - 1;

                 }

                 else

                         low = mid + 1;

        }

        cout << result << "\n";

        return 0;

}