#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
 
using namespace std;
 
typedef pair<int, int> pii;
 
map<string, pii> mp;
map<string, pii> ori;
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
 
        ori[str].first =  i;
        ori[str].second = str.size();
        int tmp = str.size();
 
        str += str;
        mp[str].first = i;        
        mp[str].second = tmp;
    }
 
    int cnt = -1;
    bool chk = false;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        for (auto it2 = ori.begin(); it2 != ori.end(); it2++)
        {
            // 문자열 A,B의 인덱스가 다르면(복사된 문자열과 원래 문자열이 같은게 아니라면)
            if (it->second.first != it2->second.first)
            {
                // 이때 서로 원래 문자열 길이 자체가 같고, 원래 문자열이 복사된 문자열내에 존재할 경우
                if (it->second.second == it2->second.second && it->first.find(it2->first) != string::npos)
                {
                    // 이미 값이 존재하면 그 값을 대입, 그게 아니면 신규값 대입
                    if (it->second.first <= -1)
                        it2->second.first = it->second.first;
                    else if (it2->second.first <= -1)
                        it->second.first = it2->second.first;
                    else
                    {
                        it->second.first = cnt;
                        it2->second.first = cnt; 
                    }
 
                    chk = true;
                }
            }
        }
 
        // cnt가 이용된 경우에만 cnt--
        if (chk)
        {
            cnt--;
            chk = false;
        }
    }
 
    // 같은 인덱스 -> 중복되는 문자열들
    map<int, int> ans;
    for (auto it = ori.begin(); it != ori.end(); it++)
        ans[it->second.first]++;
 
     cout << ans.size();
 
    return 0;
}
