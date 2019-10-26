#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() 
{
    int i;
    deque<string> ss;

    ss.push_back("May");
    ss.push_back("I");
    ss.push_back("help");
    ss.push_back("you");
    ss.push_back("?");

    for (i=0; i<ss.size(); i++) cout << ss[i] << " ";
    cout << endl;
    string a;
    ss.pop_back();
    ss.pop_front();

    ss.push_front("...");
    ss.push_front("^_^");

    for (i=0; i<ss.size(); i++) cout << ss[i] << " ";
    cout << endl;

    return 0;
}