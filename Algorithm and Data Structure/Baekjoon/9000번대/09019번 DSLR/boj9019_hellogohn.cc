#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define REGISTER 4
using namespace std;
 
typedef struct NODE {
    int num_;
    string regi_use_;
}BFS_Q;
 
int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int A, B;  cin >> A >> B;
        int is_end = 0;
        queue<NODE> bfs_queue;
        vector<int> is_visited(10000, 0);
        bfs_queue.push({ A, "" }); 
        while (bfs_queue.size() && is_end == 0) {
            NODE now_node = bfs_queue.front();  bfs_queue.pop(); 
 
            // 방문 여부 확인 
            if (is_visited[now_node.num_]) continue;
            is_visited[now_node.num_] = 1; 
 
            // 정답이면 while 탈출~
            if (now_node.num_ == B) {
                cout << now_node.regi_use_ << "\n";
                break;
            } 
 
            int jari_1000_to_1, jari_1_to_1000;
 
            // 레지스터 별 동작 조정 
            for (int register_idx = 0; register_idx < REGISTER; register_idx++)  {
                NODE new_node = {0, now_node.regi_use_ };
                switch (register_idx) {
                case 0:
                    new_node.num_ = (now_node.num_ * 2) % 10000; 
                    new_node.regi_use_ += "D"; 
                    break;
                case 1:
                    new_node.num_ = (now_node.num_ == 0 ? 9999 : now_node.num_ - 1);
                    new_node.regi_use_ += "S";
                    break;
                case 2:
                    jari_1000_to_1 = now_node.num_ / 1000;
                    new_node.num_ = (now_node.num_ % 1000) * 10 + jari_1000_to_1;
                    new_node.regi_use_ += "L";
                    break;
                case 3:
                    jari_1_to_1000 = now_node.num_ % 10;
                    new_node.num_ = (now_node.num_ / 10) % 1000 + jari_1_to_1000 *1000;
                    new_node.regi_use_ += "R";
                    break;
                }
 
                if (!is_visited[new_node.num_]){
                    if (new_node.num_ == B) { 
                        cout << new_node.regi_use_ << "\n";
                        is_end = 1;
                        break;
                    }
                    bfs_queue.push(new_node);
                }
            }
        }
    }
    return 0;
}
