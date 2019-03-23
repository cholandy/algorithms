#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
 
using namespace std;
 
typedef pair<string, string> pss;
 
map<pss, int> mp;
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
    {
        char str1[30], str2[30];
        scanf("%s %s", str1, str2);
 
        mp[{str2, str1}] = 1;
    }
 
    // 다시 넘버링(인덱스 파악용)
    int num = 1;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        it->second = num;
        num++;
    }
 
    int q;
    scanf("%d", &q);
 
    while (q--)
    {
        char str1[30], str2[30];
        scanf("%s %s", str1, str2);
 
        // 인덱스 파악
        int idx = mp[{str2, str1}];
 
        // 인덱스가 3으로 나눌때 0이 남으면 
        // 즉, A B C가 하나의 친구 그룹으로 나열될 때 A에 사람이 있다면
        if (idx % 3 == 0)
        {
            auto it = mp.lower_bound({ str2, str1 });
            it--;
            it--;
 
            printf("%s %s\n", it->first.second.c_str(), it->first.first.c_str());
            it++;
 
            printf("%s %s\n", it->first.second.c_str(), it->first.first.c_str());
            it++;
        }
 
        // 인덱스가 3으로 나눌때 2가 남으면 
        // 즉, A B C가 하나의 친구 그룹으로 나열될 때 C에 사람이 있다면
        else if (idx % 3 == 2)
        {
            auto it = mp.lower_bound({ str2, str1 });
            it--;
 
            printf("%s %s\n", it->first.second.c_str(), it->first.first.c_str());
            it++;
            it++;
 
            printf("%s %s\n", it->first.second.c_str(), it->first.first.c_str());
        }
        // 인덱스가 3으로 나눌때 1이 남으면 
        // 즉, A B C가 하나의 친구 그룹으로 나열될 때 B에 사람이 있다면
        else if (idx % 3 == 1)
        {
            auto it = mp.lower_bound({ str2, str1 });
 
            it++;
            printf("%s %s\n", it->first.second.c_str(), it->first.first.c_str());
 
            it++;
            printf("%s %s\n", it->first.second.c_str(), it->first.first.c_str());
        }
    }
 
    return 0;
}