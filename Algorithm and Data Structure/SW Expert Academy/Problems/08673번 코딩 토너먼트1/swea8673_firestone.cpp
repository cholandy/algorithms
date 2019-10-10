
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen(&quot;input.txt&quot;, &quot;r&quot;, stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int K;
        cin >> K;
        const int a = 2<<K;
        int arr[a] = {1,};
        for (int i=0; i<a; i++) {
            cin >> arr[i];
        }
        for 

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}