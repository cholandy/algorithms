#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long lint;

lint n;

int main(){
	cin >> n;
	cout << n * (n - 1) / 2;
}

