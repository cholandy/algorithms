#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
char str[3005][3005];

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    int dist = 1e9;
    for (int i=0; i<m; i++) {
        int low = -1e9;
        for (int j=0; j<n; j++) {
            if(str[j][i] == 'X') low = j+1;
            else if(str[j][i] == '#') dist = min(j - low, dist);
        }
        dist = min(n - low, dist);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            if(str[i][j] == '#'){
                putchar('#');
            }
            else if(i >= dist && str[i - dist][j] == 'X'){
                putchar('X');
            }
            else putchar('.');
        }
        puts("");
    }
}