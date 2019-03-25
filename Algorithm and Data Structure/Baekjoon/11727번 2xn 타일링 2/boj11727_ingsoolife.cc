#include <iostream>
using namespace std;

int main() {
 int N;
 int DP[1000];

 cin >> N;
 DP[0] = 1;
 DP[1] = 3;
 for (int i = 2; i < N; i++)
  DP[i] = (DP[i - 1] + (DP[i - 2] * 2)) % 10007;

 cout << DP[N - 1] << endl;
}