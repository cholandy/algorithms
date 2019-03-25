#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    // init
    int N, M;
    scanf("%d %d", &N , &M);
    vector< vector<int> > num_mat(N+1, vector<int>(M+1, 0));
    vector< vector<int> > dp_mat(N+1, vector<int>(M+1, 0));
 
    for ( int n_idx = 1 ; n_idx <= N ; n_idx++)
        for ( int m_idx = 1 ; m_idx <= M ; m_idx++)
            scanf("%d", &(num_mat.at(n_idx).at(m_idx)));
 
    // dp 벡터 초기화
    // 첫 행을 초기화 한다.
    for ( int m_idx = 1 ; m_idx <= M ; m_idx++)
        dp_mat.at(1).at(m_idx) += dp_mat.at(1).at(m_idx-1) + num_mat.at(1).at(m_idx);
    // 첫 열을 초기화 한다.
    for ( int n_idx = 2 ; n_idx <= N ; n_idx++)
        dp_mat.at(n_idx).at(1) = dp_mat.at(n_idx-1).at(1) +  num_mat.at(n_idx).at(1);
 
 
    // dp를 수행한다.
    // 한 행씩 순차적으로 갱신한다.
    for ( int n_idx = 2 ; n_idx <= N ; n_idx++)
        for ( int m_idx = 2 ; m_idx <= M ; m_idx++)
            dp_mat.at(n_idx).at(m_idx) = num_mat.at(n_idx).at(m_idx) + max({ dp_mat.at(n_idx-1).at(m_idx) ,
                                                                             dp_mat.at(n_idx).at(m_idx-1) ,
                                                                             dp_mat.at(n_idx-1).at(m_idx-1) });
 
    printf("%d", dp_mat.at(N).at(M) );
 
    return 0;
}
