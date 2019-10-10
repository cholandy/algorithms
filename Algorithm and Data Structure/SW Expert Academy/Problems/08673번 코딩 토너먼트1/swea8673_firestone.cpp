
#include <iostream>

using namespace std;

int abs(int a, int b) {
    if (a>=b) return a-b;
    return b-a;
}
int max(int a, int b) {
    if (a>=b) return a;
    return b;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("C:\\Users\\woosa\\Desktop\\algorithms\\input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int K, ans=0;
        cin >> K;
        const int a = 1<<K;
        int cnt = 1<<(1-K);
        int arr[a] = {1,};
        for (int i=0; i<a; i++) {
            cin >> arr[i];
        }
        while (cnt >=1) {
            int next = cnt>>1;
            int temp[next]={0,};
            for (int i=0; i<cnt; i++) {
                ans += abs(arr[2*i], arr[2*i+1]);
                if (i%2==0) {
                    temp[i-1] = max(arr[2*i], arr[2*i+1]);
                }
            }
            int arr[next];
            for (int i=0; i<next; i++) {
                arr[i] = temp[i];
            }
            cnt /=2;
        }
        printf("#%d %d\n", test_case, ans);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}