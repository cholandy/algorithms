#include <iostream>
#include <vector>
 
#define MAX 4000001
 
using namespace std;
 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int *prime = new int[MAX];
    fill_n(prime, MAX, 1);
    vector<int> v;
    int result;
    prime[0] = 0;
    prime[1] = 0;
     
    for(int i = 2; i < MAX; i++)
        if(prime[i]) {
            v.push_back(i);
            for(int j = i+i; j < MAX; j+=i)
                prime[j] = 0;       
        }
     
    int len = v.size();
    cout << len;
    for(int i = 0; i < len; i++) {
        result = v[i];
        for(int j = i+1; j < len; j++) {
            result += v[j];
            if(result > 4000000)
                break;
             
            prime[result]++;
             
        }
    }
     
    int N; cin >> N;
    cout<<prime[N];
     
    return 0;
     
}