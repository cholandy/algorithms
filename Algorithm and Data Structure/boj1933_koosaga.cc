#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pi;

multiset<int> s;
multiset<int> ::iterator it;
vector<pi> v;

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int s,e,x;
        scanf("%d %d %d",&s,&x,&e);
        if(s > e) continue;
        v.push_back(pi(s,x));
        v.push_back(pi(e,-x));
    }
    s.insert(0);
    sort(v.begin(),v.end());
    int bef = -1, e;
    for (int i=0; i<v.size(); i = e) {
        e = i;
        while (e < v.size() && v[i].first == v[e].first) e++;
        for (int j=i; j<e; j++) {
            if(v[j].second < 0){
                it = s.find(-v[j].second);
                s.erase(it);
            }
            else{
                s.insert(v[j].second);
            }
        }
        it = s.end();
        it--;
        if(bef == *it) continue;
        bef = *it;
        printf("%d %d ",v[i].first,bef);
    }
}