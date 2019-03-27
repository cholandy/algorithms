#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
 
int main(int argc, const char * argv[]) {
 
    vector<string> v;
    vector<string> ret;
    int N,M;
    string input;
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N+M; i++) // 듣도못한이름과 보도못한 이름을 연속된 하나의 벡터로 입력받는다.
    {
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(),v.end()); //정렬함수
    
    for(int i = 1 ; i <N+M ;i++)
    {
        if(v[i].compare(v[i-1]) == 0) // compare함수 사용, 벡터 v[i]와 v[i-1]이 같으면 0
        {
            ret.push_back(v[i]);
        }
    }
    cout << ret.size()<<'\n'; //벡터 ret의 size는 중복된 개수를 의미함.
    for(int i = 0; i < ret.size();i++)
    {
        cout << ret[i]<<'\n'; //출력
    }
  
    return 0;
}