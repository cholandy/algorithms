#include    <cstdio>
#include    <vector>
#include    <algorithm>
#pragma warning (disable : 4996)
 
std::vector<int> parts;
int bs(int num, int s, int e)
{
    int start = s, end = e;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (parts[mid] == num)  return mid;
        else if (parts[mid] < num)   start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
 
int main()
{
    int x, n;
    bool flg;
 
    while (scanf("%d", &x) == 1) //입력이 있다면 scanf는 1을 리턴
    {
        x *= 10000000;
        scanf("%d", &n);
        int tmp;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &tmp);
            parts.push_back(tmp);
        }
        std::sort(parts.begin(), parts.end());
        flg = false;
        for (int i = 0; i < parts.size(); ++i)
        {
            int temp = bs(x - parts[i], i + 1, parts.size() - 1);
            if (temp != -1)
            {
                flg = true;
                printf("yes %d %d\n", parts[i], parts[temp]);
                break;
            }
        }
        if (!flg)
            printf("danger\n");
 
        parts.clear();
    }
}