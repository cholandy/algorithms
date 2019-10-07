#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
 
typedef struct NODE {
    struct NODE *next[12];
    int end;
    NODE() : next(), end(0) {};
}node;
 
node *makenewnode()
{
    node *newnode = (node*)malloc(sizeof(node));
    for (int i = 0; i < 10; i++)
        newnode->next[i] = 0;
    newnode->end = 0;
    return newnode;
}
 
bool push(node **origin, char *arr)
{
    int len = strlen(arr);
    node *tmp = *origin;
 
    for (int i = 0; i < len; i++)
    {
        if (!tmp->next[arr[i] - '0'])
        {
            if (tmp->end) return false;
            tmp->next[arr[i] - '0'] = makenewnode();
        }
        tmp = tmp->next[arr[i] - '0'];
    }
 
    tmp->end = 1;
    for (int i = 0; i < 10; i++)
    {
        if (tmp->next[i]) return false;
    }
    return true;
}
 
void delnode(node * origin)
{
    node *pre = origin;
    for (int i = 0; i < 10; i++)
        if (pre->next[i])
            delnode(pre->next[i]);
    delete pre;
    return;
}
 
int main(void)
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        char arr[10005][12];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        bool check = true;
        node *origin = makenewnode();
        for (int i = 0; i < N; i++)
        {
            check = push(&origin, arr[i]);
            if (!check) break;
        }
 
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
        delnode(origin);
    }
    return 0;
}