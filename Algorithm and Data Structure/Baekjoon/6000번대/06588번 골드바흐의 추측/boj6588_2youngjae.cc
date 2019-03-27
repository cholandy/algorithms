#include <iostream>
#include <vector>
#define P pair<int,int>
using namespace std;
 
int primes[1000001];
vector<int> v;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    //에라토스테네스의 체
    for (int i = 2; i <= 1000000; i++) {
        for (int j = 2; i*j <= 1000000; j++) {
            if (primes[i*j])continue;
            primes[i*j] = true;
        }
    }
    //3이상 소수 벡터에 푸쉬
    for (int i = 3; i <= 1000000; i++) {
        if (!primes[i])v.push_back(i);
    }
 
    int x;
    while (true) {
        cin >> x;
        //종료조건
        if (x == 0)break;
 
        //두 소수의 합으로 표현 가능한지 확인
        for (int i = 0; i < v.size(); i++) {
            if (!primes[x - v[i]]) {
                cout << x << " = " << v[i] << " + " << x - v[i] << "\n";
                break;
            }
        }
    }
 
}
