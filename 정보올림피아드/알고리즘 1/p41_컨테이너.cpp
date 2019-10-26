#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i;
    vector<string> ss;
    ss.reserve(5);
    
    ss.push_back("May");
    ss.push_back("I");
    ss.push_back("help");
    ss.push_back("you");
    ss.push_back("?");

    for (i=0; i<ss.size(); ++i) cout << ss[i] << " ";
    cout << endl;

    ss.pop_back();
    ss.push_back("...");
    ss.push_back("^_^");

    for (i=0; i<ss.size(); ++i) cout << ss[i] << " ";
    cout << endl;

    cout << ss.front() << " " << ss.back() << endl;

    return 0;
}