#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "I am a boy", cp;
    int i;
    str = "I am a girl";
    str += " and I am sixteen";

    if (str == "I am a boy") cout << "Same String" << endl;
    else cout << "Different String" << endl;

    cp = str.substr(7,4);

    // 문자 하나씩 출력
    for (i=0; i<str.length(); i++) cout << str[i] << endl;

    // "girl" 문자열 찾기
    cout << "girl index" << str.find("girl") << endl;

    return 0;
}