#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int n;
 
    scanf("%d", &n);
    
    if(n <= 2 || n >= 4)
    {
        printf("Woof-meow-tweet-squeek");
        return 0;
    }
 
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        if ((a == 1 && b == 3) || (a == 3 && b == 1)){}
        else if (a == 1 && b == 4 || (a == 4 && b == 1)){}
        else if (a == 3 && b == 4 || (a == 4 && b == 3)){}
        else
        {
            printf("Woof-meow-tweet-squeek");
            return 0;
        }
    }
 
    printf("Wa-pa-pa-pa-pa-pa-pow!");
    return 0;
}
