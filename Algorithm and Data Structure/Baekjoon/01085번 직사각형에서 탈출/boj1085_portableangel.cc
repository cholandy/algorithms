#include <iostream>

using namespace std;

int main()
{
	int x, y;
	int w, h;

	cin>>x>>y>>w>>h;

	int min;

	min=(x<y)?x:y;
	min=(min<w-x)?min:w-x;
	min=(min<h-y)?min:h-y;

	cout<<min;

	return 0;
}
