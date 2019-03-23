#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    string str;
    cin >> str;
 
    int star = 0;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'S')
        {
            str.insert(str.begin() + i, '*');
            i++;
            len++;
            star++;
        }
        else if (str[i] == 'L')
        {
            str.insert(str.begin() + i, '*');
            i += 2;
            len++;
            star++;
        }
    }
    str.push_back('*');
    star++;
    
    bool chk = true;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'L')
        {
            chk = false;
            break;
        }
    }
    if (chk)
        cout << star - 1;
    else
        cout << star;
    return 0;
}