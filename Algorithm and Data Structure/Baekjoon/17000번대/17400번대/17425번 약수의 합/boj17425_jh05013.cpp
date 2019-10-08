#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
void OJize(){
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
}

ll ds[1001001];

const int MX = 1000000;

int main()
{
    OJize();
    for(int i=1; i<=MX; i++) {
        for(int j=i; j<=MX; j+=i) {
            ds[j]+= i;
        }
    }
    for(int i=1; i<=MX; i++) {
        ds[i]+= ds[i-1];
    }
    int Q; 
    cin>>Q;
    while(Q--){
        int n; cin>>n;
        cout<<ds[n]<<'\n';
    }
}