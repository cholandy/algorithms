#include <iostream>

using namespace std;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int N;

        cin >> N;

 

        int result = 0;

        int num = 1;

       

        while (1)

        {

                 long long temp = 1LL * (num*(num + 1) / 2);

                 if (temp > N)

                         break;

 

                 if ((N - temp) % num == 0)

                         result++;

                 num++;

        }

        cout << result << "\n";

        return 0;

}