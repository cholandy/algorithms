#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int tc;scanf("%d", &tc);
    for (int k = 0; k<tc; ++k) {
        int a=0,b=0,c=0,d=0;
        cin >> a >> b >> c >> d;
        int ans =0 ;
        int n =0;
        cin >> n;
        for (int i =0; i < n;++i) {
            int x=0,y=0,r=0;
            cin >> x >> y >> r;
            int q=0,w=0,e=0,t=0;
            q = a-x;
            w = b-y;
            e = c-x;
            t = d-y;
            if ((q*q + w*w < r*r) != (e*e + t*t < r*r)) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}