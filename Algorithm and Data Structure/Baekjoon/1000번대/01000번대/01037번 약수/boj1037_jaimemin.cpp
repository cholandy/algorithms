#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 50;
int numOfDivisor;

vector<int> divisor;
int getNumber(void) {
    sort(divisor.begin(), divisor.end()); //오름차순으로 정렬
    int number = divisor[0] * divisor[numOfDivisor - 1]; //첫번째 약수 * 마지막 약수
    return number;
}

int main(void)
{
    cin >> numOfDivisor;
    for (int i = 0; i < numOfDivisor; i++)
    {
        int num;
        cin >> num;
        divisor.push_back(num);
    }
    cout << getNumber() << endl;
    return 0;
}