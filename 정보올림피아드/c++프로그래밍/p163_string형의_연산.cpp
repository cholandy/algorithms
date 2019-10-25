#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100] = "I am a boy.", cp[100];
    int i;
    strcpy(str, "I am a girl");
    strcat(str, " and I am sixteen");

    if (strcmp(str, "I am a boy.") == 0) cout << "Same String" << endl;
    else cout << "Different String" << endl;

    strncpy(cp, str+7, 4);
    for (i=0; i<strlen(str); i++) cout << str[i];
    cout << endl;
    for (i=0; i<strlen(cp);i++) cout << cp[i];
    cout << endl;

    return 0;
}