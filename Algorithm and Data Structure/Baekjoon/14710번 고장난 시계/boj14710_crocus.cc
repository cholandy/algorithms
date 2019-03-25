#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
bool chk[500][500];
 
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
 
    double h = 0, m = 0;
    while (1)
    {
        double tmp = floor(h);
        if((int)h == (int)tmp)
            chk[(int)h][(int)m] = true;
 
        m += 1.0;
        h += (double)1 / 12;
 
        if (m >= 360.0)
            m = 0.0;
        if (h >= 360.0)
            break;
    }
 
    if (chk[a][b])
        printf("O");
    else
        printf("X");
    return 0;
}