#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
 
using namespace std;
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }
 
char tmp[1000001];
 
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
    int n;
    string s, p;
 
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
        cin >> tmp[i];
 
    p = tmp;
    s = tmp;
    s += s;
 
    s.pop_back();
 
    for (int i = 0; i < n; i++)
        cin >> tmp[i];
 
    vector<int> ans = kmp(s, p);
 
    int a = ans.size();
    int t = gcd(a, n);
    a /= t;
    n /= t;
 
    cout << a << "/" << n << endl;
 
    return 0;
}