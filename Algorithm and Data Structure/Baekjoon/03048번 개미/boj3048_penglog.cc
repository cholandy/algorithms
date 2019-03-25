#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);
 
    int n1, n2, cnt;
    cin >> n1 >> n2;
    int size = n1 + n2;
    vector<char> str(size);
    // 방향 구분을 위해 ->는 소문자 <- 는 대문자로 입력
    for (int i = 1; i <= n1; i++) {
        cin >> str[n1 - i];
        str[n1 - i] = str[n1 - i] - 'A' + 'a';
    }
    for (int i = n1; i < size; i++)
        cin >> str[i];
    cin >> cnt;
 
    while (cnt--) {
        for(int i = 1; i < size; i++){
            // -> <- 일 경우 스왑
            if(str[i-1] >= 'a' && str[i-1] <= 'z'
                && str[i] >= 'A' && str[i] <= 'Z'){
                char tmp = str[i-1];
                str[i-1] = str[i];
                str[i] = tmp;
                i++; // 탐색을 했으므로 스킵
            }
        }
    }
    for (auto i : str) {
        if (i >= 'a' && i <= 'z')
            cout << char(i + 'A' - 'a');
        else
            cout << i;
    }
 
    return 0;
}
