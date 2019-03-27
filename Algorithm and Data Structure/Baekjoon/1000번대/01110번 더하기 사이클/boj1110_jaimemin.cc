#include <iostream>

using namespace std;

 

const int MAX = 99;

 

int N;

 

int numOfCycle(void)

{

        int cnt = 0;

        int temp = N;

        while (1)

        {

               ++cnt;

               int tenth_digit = temp / 10; //십의자리

               int unit = temp % 10; //일의 자리

               int addResult = tenth_digit + unit; //십의자리 숫자와 일의자리 숫자 더한 값

               //기저사례

               temp = unit * 10 + addResult % 10; //새로운 숫자

               if (temp == N)

                       break;

        }

        return cnt;

}

 

int main(void)

{

        cin >> N;

       

        cout << numOfCycle() << endl;

        return 0;

}