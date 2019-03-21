#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int f[10] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

int n;
char pan[5][5];
bool vis[5][5];
bool chk[2400005];
int p;
int trie[2400005][26];
int scr[2400005];

void dfs(int x, int y, int v){
	chk[v] = 1;
	vis[x][y] = 1;
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(i == 0 && j == 0) continue;
			if(x + i < 0 || y + j < 0 || x + i >= 4 || j + y >= 4 || vis[x+i][y+j]) continue;
			if(!trie[v][pan[x+i][y+j] - 'A']) continue;
			dfs(x + i, y + j, trie[v][pan[x+i][y+j] - 'A']);
		}
	}
	vis[x][y] = 0;
}

int ans1, ans2;
string opt;

void dfs2(int x, string &s){
	if(scr[x]){
		ans1 += f[scr[x]];
		ans2++;
		if(opt.size() < s.size()) opt = s;
	}
	for(int i=0; i<26; i++){
		if(trie[x][i] && chk[trie[x][i]]){
			s.push_back(i + 'A');
			dfs2(trie[x][i], s);
			s.pop_back();
		}
	}
}

char buf[11];

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",buf);
		int l = strlen(buf);
		if(l > 8) continue;
		int pos = 0;
		for(int j=0; buf[j]; j++){
			if(!trie[pos][buf[j] - 'A']){
				trie[pos][buf[j] - 'A'] = ++p;
			}
			pos = trie[pos][buf[j] - 'A'];
		}
		scr[pos] = l;
	}
	int q;
	cin >> q;
	while(q--){
		memset(chk, 0, sizeof(chk));
		for(int i=0; i<4; i++){
			cin >> pan[i];
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(trie[0][pan[i][j] - 'A']){
					dfs(i, j, trie[0][pan[i][j] - 'A']);
				}
			}
		}
		ans1 = ans2 = 0; opt.clear();
		string aux;
		dfs2(0, aux);
		printf("%d %s %d\n", ans1, opt.c_str(), ans2);
	}
}

