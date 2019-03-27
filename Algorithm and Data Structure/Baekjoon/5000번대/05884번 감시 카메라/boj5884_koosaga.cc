#include <cstdio>

int x[50005], y[50005];

int n;

int f(int piv){
    int visited[50005]={};
    for(int i=0; i<3; i++){
        int obj = -1;
        for (int i=0; i<n; i++) {
            if(visited[i] == 0) obj = i;
        }
        if(obj == -1) return 1;
        if(piv&1){
            for (int i=0; i<n; i++) {
                if(x[obj] == x[i]) visited[i] = 1;
            }
        }
        else{
            for (int i=0; i<n; i++) {
                if(y[obj] == y[i]) visited[i] = 1;
            }
        }
        piv>>=1;
    }
    for (int i=0; i<n; i++) {
        if(visited[i] == 0) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&x[i],&y[i]);
    }
    for (int i=0; i<=7; i++) {
        if(f(i)){
            puts("1");
            return 0;
        }
    }
    puts("0");
}