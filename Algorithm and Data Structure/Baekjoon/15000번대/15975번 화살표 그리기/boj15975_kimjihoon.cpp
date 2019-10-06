#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

long long a[100009], m[100009];
pair<long long, long long> p[100009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, y, s = 0;
	cin>>n;
	for (int i = 0; i <= n; i++)
        m[i] = -1;
    for (int i = 1; i <= n; i++)
        cin>>p[i].first>>p[i].second;
    sort(p+1, p+n+1);
	for (int i = 1; i <= n; i++){
        long long x = p[i].first, y = p[i].second;
        if (m[y] != -1){
            a[i] = x - p[m[y]].first;
            if (a[m[y]] == -1)
                s += a[i];
            else if (a[m[y]] > a[i])
                s -= a[m[y]] - a[i];
            s += a[i];
        }
        else
            a[i] = -1;
        m[y] = i;
	}
	cout<<s<<'\n';
	return 0;
}
