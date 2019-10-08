#pragma warning(disable : 4996)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << *it << ' ';
    printf("\n");
    for (auto elem : v1)
        cout << elem << ' ';
    cout << '\n';
    set<int> s1 = {2, 2, 3, 4, 5};
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    for (auto elem : s1)
        cout << elem << ' ';
}