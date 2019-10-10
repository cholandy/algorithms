
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


void print_array(int arr[], int len) {
    for (int i=0; i<len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int K, ans=0;
        cin >> K; // 잘 나옴
        const int a = 1<<K;
        int cnt = 1<<(K-1);
        int arr[a];
        for (int i=0; i<a; i++) {
            cin >> arr[i];
        }
        while (cnt >=1) {
            for (int i=0; i<cnt; i++) {
                ans += abs(arr[2*i], arr[2*i+1]);
                arr[i] = max(arr[2*i], arr[2*i+1]);   
            }
            cnt /=2;
        }
        printf("#%d %d\n", test_case, ans);

	}
	return 0;
}