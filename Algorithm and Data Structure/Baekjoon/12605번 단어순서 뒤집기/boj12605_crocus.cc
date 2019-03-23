#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
    scanf("%d ", &n);
 
    for(int i = 1; i <= n; i ++)
    {
        string str;
        getline(cin, str);
        reverse(str.begin(), str.end());
        str += ' ';
        vector<string> vc;
 
        int len = str.size();
 
        int start = 0;
        for (int end = 0; end < len; end++)
            if (str[end] == ' ')
            {
                reverse(str.begin() + start, str.begin() + end);
                start = end + 1;
            }
 
        cout << "Case #" << i << ": " << str << endl;
    }
    return 0;
}
