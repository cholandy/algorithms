#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
long long int sol;

void dfs(long long int s) {
	int sizee = v.size();
	if (sizee == 2) {
		if (s > sol) sol = s;
		return;
	}
	int now;
	long long int tmp;
	for (int i = 1; i < sizee - 1; i++) {
		now = v[i];
		tmp = v[i - 1] * v[i + 1];
		v.erase(v.begin() + i);
		dfs(s + tmp);
		v.insert(v.begin() + i, now);
	}

	return;
}
int main() {
	cin >> N;
	int e;
	for (int i = 0; i < N; i++) {
		cin >> e;
		v.push_back(e);
	}

	dfs(0);
	cout << sol << endl;
	return 0;
}