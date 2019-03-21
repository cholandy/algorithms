#include<cstdio>
#include<algorithm>
 
using namespace std;
 
pair<int,int> a[111111];
 
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&a[i].second,&a[i].first);
    sort(a,a+n);
    for(i=0;i<n;i++)printf("%d %d\n",a[i].second,a[i].first);
    return 0;
}