#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pzl[3], wrd[6];

void wookje() {
	bool chk[6] = { 0 };
	int cnt = 0;

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 6; i++) {
			if (!chk[i] && pzl[k] == wrd[i]) {
				chk[i] = 1, cnt++;
				break;
			}
		}
		for (int i = 0; i < 6; i++) {
			if (!chk[i] && pzl[0][k] == wrd[i][0] && pzl[1][k] == wrd[i][1] && pzl[2][k] == wrd[i][2]) {
				chk[i] = 1, cnt++;
				break;
			}
		}
	}
	if (cnt == 6) {
		for (int i = 0; i < 3; i++) cout << pzl[i] << "\n";
		exit(0);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 6; i++) cin >> wrd[i];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				if (i == j || j == k || k == i) continue;
				pzl[0] = wrd[i], pzl[1] = wrd[j], pzl[2] = wrd[k];
				wookje();
			}
		}
	}

	cout << "0";

	return 0;
}