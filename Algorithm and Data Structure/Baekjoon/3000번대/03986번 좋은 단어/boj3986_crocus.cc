#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
 
using namespace std;
 
int main()
{
    int n;
    scanf("%d", &n);
 
    int ans = 0;
 
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
 
        stack<char> st;
 
        int len = str.size();
        for (int j = 0; j < len; j++)
        {
            if (!st.empty() && st.top() == str[j])
            {
                st.pop();
                continue;
            }
            st.push(str[j]);
        }
 
        if (st.empty())
            ans++;
    }
 
    printf("%d", ans);
    return 0;
}
