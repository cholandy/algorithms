#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
 
using namespace std;
 
string str[105];
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    int nn = n * 2 - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
 
        string tmp = str[i];
        reverse(tmp.begin(), tmp.end());
 
        str[i] += tmp;
 
        str[nn] = str[i];
        nn--;
    }
 
    int y, x;
    scanf("%d %d", &y, &x);
 
    y--, x--;
    if(str[y][x] == '#')
    {
        str[y].erase(str[y].begin() + x, str[y].begin() + x + 1);
        str[y].insert(str[y].begin() + x, '.');
    }
    else
    {
        str[y].erase(str[y].begin() + x, str[y].begin() + x +1 );
        str[y].insert(str[y].begin() + x, '#');
    }
 
    for (int i = 0; i < 2 * n; i++)
        cout << str[i] << endl;
        
 
    return 0;
}