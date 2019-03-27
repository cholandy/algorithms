#include<cstdio>
#include<algorithm>

int a[111111];

int main()
{
    int i,j,n,t=0,s=0,r=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        s+=a[i];
    }
    for(i=j=0;i<n;i++)
    {
        while(std::min(t,s-t)<std::min(t+a[j],s-t-a[j]))
        {
            t+=a[j];
            j++;
        }
        r=std::max(r,std::min(t,s-t));
        t-=a[i];
    }
    printf("%d",r);
}
