#include <bits/stdc++.h>

using namespace std;

void func(vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = v[i] % 2;
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    func(v);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';
    }
    return 0;
}