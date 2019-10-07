#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
 
using namespace std;
 
int value[10002];
int dp[10002][2];
vector<int> vc[10002];
vector<int> ans;
 
int dfs(int prev, int here, bool chk)
{
   int &ret = dp[here][chk];
 
   if (ret != -1)
      return ret;
 
   if(chk)
       ret = value[here];
    
   else ret = 0;
 
   for (auto next : vc[here])
   {
      if (next == prev)
         continue;
 
      if (chk)
         ret += dfs(here, next, 0);
 
      else
         ret += max(dfs(here, next, 0), dfs(here, next, 1));
   }
 
   return ret;
}
 
void trace(int prev, int here, bool chk)
{
   if (chk)
   {
      ans.push_back(here);
      for (auto next : vc[here])
      {
         if (next == prev)
            continue;
 
         trace(here, next, 0);
      }
   }
 
   else
   {
      for (auto next : vc[here])
      {
         if (next == prev)
            continue;
 
         if (dp[next][1] >= dp[next][0])
            trace(here, next, 1);
         else
            trace(here, next, 0);
      }
   }
}
int main()
{
   memset(dp, -1, sizeof(dp));
 
   int n;
   scanf("%d", &n);
 
   for (int i = 1; i <= n; i++)
      scanf("%d", &value[i]);
 
   for (int i = 0; i < n - 1; i++)
   {
      int from, to;
      scanf("%d %d", &from, &to);
 
      vc[from].push_back(to);
      vc[to].push_back(from);
   }
 
   int a = dfs(-1, 1, 0);
   int b = dfs(-1, 1, 1);
 
   if (a >= b)
      trace(-1, 1, 0);
   else
      trace(-1, 1, 1);
 
   sort(ans.begin(), ans.end());
 
   printf("%d\n", max(a, b));
   for (auto i : ans)
      printf("%d ", i);
 
   return 0;
}