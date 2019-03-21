#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a[100001];
pair<int, int> r[100001];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int i, j, n;
		scanf("%d", &n);
		for (i = 0; i < 100000; i++) a[i].clear();
		while (n--)
		{
			scanf("%d%d", &i, &j);
			a[i].push_back(j);
		}
		n = 0;
		r[0].first = 0;
		r[0].second = 0;
		for (i = 0; i < 100000; i++) if (!a[i].empty())
		{
			sort(a[i].begin(), a[i].end());
			if (a[i][0] == r[n].second)
			{
				for (j = 0; j < a[i].size(); j++)
				{
					n++;
					r[n].first = i;
					r[n].second = a[i][j];
				}
			}
			else
			{
				for (j = a[i].size() - 1; j >= 0; j--)
				{
					n++;
					r[n].first = i;
					r[n].second = a[i][j];
				}
			}
		}
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &i);
			printf("%d %d\n", r[i].first, r[i].second);
		}
	}
}