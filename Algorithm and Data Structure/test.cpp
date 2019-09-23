#include <iostream>
#include <string>


using namespace std;

void printString(const string& myString) {
    cout << myString << endl;
}

int main() {
    string someString = "Hello World!";
    printString(someString);
    printString("What the hell");
    return 0;
}
