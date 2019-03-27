#include<iostream>
#include<algorithm>
#define MAX 1000
#pragma warning(disable : 4996)
using namespace std;
 
int matrix[MAX][MAX] = { 0 };
int answer[MAX][MAX] = { 0 };
int n, m;
int bigger = 0; 
 
int main(void) {
    cin >> n >> m;
    // matrix 행렬 초기화 
    for ( int n_idx = 0 ; n_idx < n ; n_idx++){
        for (int m_idx = 0; m_idx < m; m_idx++) {
            int sub;
            scanf("%1d", &sub);
            matrix[n_idx][m_idx] = sub;
        }
    }
 
    // answer 초기화  
    for (int n_idx = 0; n_idx < n; n_idx++)  answer[n_idx][0] = matrix[n_idx][0] ? 1 : 0 ;
    for (int m_idx = 0; m_idx < m; m_idx++)  answer[0][m_idx] = matrix[0][m_idx] ? 1 : 0;
    // 1,1 에서 오류 방지하려면 초기화 필요
    bigger = answer[0][0];
 
    // 값 구하기 
    for (int n_idx = 1; n_idx < n; n_idx++){
        for (int m_idx = 1; m_idx < m; m_idx++) {
            //  1이 아니면 넘긴다. 
            if (matrix[n_idx][m_idx] == 1) {
                // 1이면 최소값 + 1 로 결정. 
                answer[n_idx][m_idx] = min({ answer[n_idx - 1][m_idx],
                    answer[n_idx][m_idx - 1], answer[n_idx - 1][m_idx - 1] }) + 1;
                if (bigger < answer[n_idx][m_idx])  bigger = answer[n_idx][m_idx];
            }
        }
    }
 
    cout << bigger*bigger;
 
    return 0;
}