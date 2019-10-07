#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
typedef pair<int, int> pii;
 
string s, p[502];
int dp[100004];
 
vector<pair<pii, int > > vc;
map<string, int> mp;
 
vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;
 
    vector<int> pi(m, 0);
 
    for (int i = 1; i< m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
vector<int> kmp(string s, string p)
{
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j>0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ans;
}
 
int main()
{
    cin >> s;
 
    int n;
    cin >> n;
 
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
 
        if (!mp.count(t))
        {
            mp[t] = 1;
            p[idx] = t;
            idx++;
        }
    }
 
    for (int i = 0; i < idx; i++)
    {
        vector<int> ans = kmp(s, p[i]);
        int len = ans.size();
        for (int j = 0; j < len; j++)
        {
            int start = ans[j];
            int end = ans[j] + p[i].size() - 1;
            int size = p[i].size();
            vc.push_back({ {start,end},size });
        }
    }
 
    sort(vc.begin(), vc.end());
 
    for (int i = 0; i < vc.size(); i++)
    {
        int start = vc[i].first.first;
        int end = vc[i].first.second;
        int size = vc[i].second;
 
        for (int j = 0; j <= end - size + 1; j++)
            dp[end + 1] = max(dp[j] + size, dp[end + 1]);
    }
 
    int cnt = 0;
    for (int i = 0; i <= s.size(); i++)
        cnt = max(cnt, dp[i]);
 
    cout << cnt;
 
    return 0;
}


출처: https://www.crocus.co.kr/1107?category=159837 [Crocus]