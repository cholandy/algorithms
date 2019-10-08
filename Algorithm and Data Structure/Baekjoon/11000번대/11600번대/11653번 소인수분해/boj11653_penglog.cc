#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
 
    int input;
    cin >> input;
 
    // 입력이 1일 경우 연산하지 않고 바로 종료
    if (input == 1) return 0;
    
    // 에라테네스의 체 이용하여 소수 리스트 만들기
    // 소수를 판별할 리스트는 최대 input의 루트 값까지
    int maxNum = sqrt(input) + 1;
    vector <bool> isPrime(maxNum + 1, false);
    vector <int> pnum;
    
    for (int i = 2; i <= maxNum; i++)
        isPrime[i] = true;
 
    for (int i = 2; i <= maxNum; i++) {
        if (isPrime[i]) {
            pnum.push_back(i);
            for (int j = i * 2; j <= maxNum; j += i)
                isPrime[j] = false;
        }
    }
    
    for (int i = 0; i < pnum.size(); i++) {
        while (input % pnum[i] == 0) {
            input /= pnum[i];
            cout << pnum[i] << "\n";
        }
    }
    // 소수 리스트에 없는 수가 남았을 때 == 소수 (자기자신 포함)
    if (input > 1)
        cout << input << "\n";
    
    return 0;
}