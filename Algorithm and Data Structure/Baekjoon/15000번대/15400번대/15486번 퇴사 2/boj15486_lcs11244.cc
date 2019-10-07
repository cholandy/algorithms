#include <iostream>
#define MX_SIZE 1500002
#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
using namespace std;
 
struct MAP {
    int day, pay;
}map[MX_SIZE];
 
long long dp[MX_SIZE];
int N, dab;
 
int main(void)
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> map[i].day >> map[i].pay;
 
    for (int i = 1; i <= N + 1; i++)
    {
        dab = MAX(dab, dp[i]);
        if (i + map[i].day > N + 1) continue;
        dp[i + map[i].day] = MAX(dab + map[i].pay, dp[i + map[i].day]);
    }
    cout << dab << endl;
    return 0;
}