#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
 
using namespace std;
 
priority_queue<double> pq;
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        double val;
        scanf("%lf", &val);
 
        if (pq.size() >= 7)
        {
            if (pq.top() > val)
            {
                pq.pop();
                pq.push(val);
            }
        }
        else
            pq.push(val);
    }
 
    vector<double> vc;
    while (!pq.empty())
    {
        vc.push_back(pq.top());
        pq.pop();
    }
 
    reverse(vc.begin(), vc.end());
 
    for (auto i : vc)
        printf("%.3lf\n", i);
 
    return 0;
}