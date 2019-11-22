#include <cstdio>
#include <algorithm>
using namespace std;
 
struct Trie{
    Trie *go[26];
    bool output;
    int branch; // 가지, 즉 자식 노드의 개수
    int words; // 현재 노드 서브트리에 있는 단어의 개수
 
    // 생성자
    Trie(): output(false), branch(0), words(0){ fill(go, go+26, nullptr); }
    // 소멸자
    ~Trie(){
        for(int i=0; i<26; i++)
            if(go[i]) delete go[i];
    }
    // 트라이에 단어를 삽입하는 함수
    void insert(char *str){
        if(*str == '\0'){
            branch++;
            output = true;
        }
        else{
            if(!go[*str-'a']){
                branch++;
                go[*str-'a'] = new Trie;
            }
            words++;
            go[*str-'a']->insert(str+1);
        }
    }
    // 현재 노드에서 더 필요한 총 타이핑 횟수를 세는 재귀 함수
    long long cntKeystrokes(bool isRoot=false){
        long long result = 0;
        // 맨 처음이거나, 현재로부터 도달가능한 단어가 2개 이상이면 속한 단어 개수만큼 타이핑++
        // 바꿔 말하면, 위 경우가 아니면 타이핑이 필요없다
        if(isRoot || branch > 1) result = words;
        // 각 자식들의 결과를 모두 더해서 반환
        for(int i=0; i<26; i++)
            if(go[i]) result += go[i]->cntKeystrokes();
        return result;
    }
};
 
int main(){
    int N;
    while(scanf("%d", &N) > 0){
        Trie *root = new Trie;
        for(int i=0; i<N; i++){
            char W[81];
            scanf("%s", W);
            root->insert(W);
        }
        printf("%.2lf\n", 1.0*root->cntKeystrokes(true)/N);
        delete root;
    }
}