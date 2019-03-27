#include <bits/stdc++.h>

using namespace std;

vector <int> A;
vector <int> B;
vector <int> C;
vector <int> D;
vector <int> E;
vector <int> F;
long long answer=0;
int N;
void ans(int e)
{
   if(e>=N*N)
       return;
   if(binary_search(F.begin(), F.end(), -1*E[e]))
   answer+=upper_bound(F.begin(), F.end(), -1*E[e])-lower_bound(F.begin(), F.end(), -1*E[e]);
   ans(e+1);
   return;
}
int main()
{
   int a, b, c, d;
   scanf("%d", &N);
   A.resize(N);
   B.resize(N);
   C.resize(N);
   D.resize(N);
   for(int i=0; i<N; i++)
   {
       scanf("%d %d %d %d", &a, &b, &c, &d);
       A[i]=a;
       B[i]=b;
       C[i]=c;
       D[i]=d;
   }
   for(int i=0; i<N; i++)
   {
       for(int j=0; j<N; j++)
       {
           a=A[i]+B[j];
           b=C[i]+D[j];
           E.push_back(a);
           F.push_back(b);
       }
   }
   sort(F.begin(), F.end());
   ans(0);
   printf("%lld", answer);
   return 0;

}