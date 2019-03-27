#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<int> vtr;

void dfs() {
	if (vtr.size() == m) {	// 가득 찼다면 출력.
									// -> 직전의 dfs로 복귀하여 pop하고 다음for문
		for (int i = 0; i < m; i++) {
			cout << vtr[i] << " ";
		}
		cout << "\n";
	}

	// 현재 위치에서의 idx
	for (int i = 1; i <= n; i++) {
		// vtr가 가득차지 않았고, (원소를 더 넣어야한다)
		// (vtr이 비어있거나 vtr의 마지막 원소가 i보다 작거나 같을경우)
			// -> 마지막 원소는 i가 들어갈 위치의 바로 직전 원소이므로
			//     i보다 작거나 같아야 오름차순으로 vtr에 숫자가 push됨
		if (vtr.size() < m && (vtr.size() == 0 || vtr[vtr.size() - 1] <= i)) {
			vtr.push_back(i);
			dfs();
			vtr.pop_back();
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n >> m; // n : 최대 숫자 // m : length

	dfs();

}
