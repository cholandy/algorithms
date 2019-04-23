"""
RMQ = Range Minimun Query
배열 A[1], ..., A[N]이 있고 다음과 같은 연산을 수행해야 한다. 
최소값: A[i], ... , A[j] 중에서 최소값을 찾아 출력한다. => 쿼리
이러한 연산이 총 M개 주어진다. 

쿼리는 독립적이다. 쿼리 하나를 구하는 시간을 구한 뒤 M을 곱하면 최종적인 시간복잡도가 나온다.
쿼리 하나의 시간 복잡도는 O(N)이다. 따라서 최종적으로 O(MN)

A[] = [3,6,2,5,3,1,8,9,7,3,5]

시간복잡도 구하기
1. 선처리: preprocessing. 선처리는 한 번만 하고 쿼리를 여러번 수행한다. 
2. 쿼리: query. 
2번이 훨씬 중요한 시간 복잡도이다. 
먼저 루트N으로 나눈다. 영어로는 sqrt decomposition이라고 한다. 수가 n개 있으면 루트 n개로 나눈다. 그룹을 지어주는 것과 동일하다. n개를 루트n 곱하기 루트n으로 나눈다. 그래서 그룹의 갯수와 그룹의 크기가 루트n으로 동일하다. 
지금 11개의 수가 있다. 루트11을 하면 3... 이 나온다. 그래서 3개씩 나눈다. R=3이다. 앞에서부터 3개씩 묶어서 총 4개의 그룹으로 만들었다. 
그룹에 최소값은 그룹에 들어가있는 수의 최소값이다. 첫 번째 그룹의 최소값은 2이다. 두 번째 그룹의 최소값은 1이다. 세 번째는 7이고 네 번째는 3이다. 
이를 정리하면 Group[0]=2, Group[1]=1, Group[2]=7, Group[3]=3
for (int i=0; i<n; i++){
    if (i%r == 0) {
        group[i/r] = a[i];
    } else {
        group[1/r] = min(group[i/r], )
    }
}

최소값을 구하는 쿼리 i, j 는 두 가지 경우가 있다. (i<=j)
첫 번째는 그룹이 같은 경우. 

두 번째는 그룹이 다른 경우. 즉 A[1] ~ A[9]의 최소값을 구하는 경우. 
시작 그룹에 들어가 있는 수는 하나씩 비교해야 한다. 그래도 R을 넘지 않는다. 이거는 끝 그룹에도 마찬가지다. 시작과 끝은 하나씩 비교해준다. 남은 부분은 사이에 있는 값들. 사이에 있는 그룹은 전체가 포함된다. 여기서 그룹을 나눈 것을 이용한다. 그룹의 최소값을 이용해주면 된다. 
while True:
    ans = min(ans, a[start])
    start +=1
    if start%r==0:
        break
While True:
    ans = min(ans, a[end])
    end -=1
    if end%r==r-1:
        break

하지만 실제로는 이 방법을 많이 쓰지 않는다. 최종적으로 N+M루트N

다음은 segment tree
이게 제일 중요한 부분이다. 

트리는 노드가 있다. 모든 노드는 두 개의 수로 이루어져 있다. s, e
s 부터 e까지. 해당 노드가 담당하는 시작 인덱스와 끝 인덱스를 의미한다. 
우리는 트리의 어떤 값들을 하나씩 저장할 것. 각 노드는 2개의 자식 노드를 갖는다. 
첫 번째 자식 노드는 s ~ m, 두 번째 자식 노드는 m+1 ~ e. 절반씩 갖는다.
           0 ~ 9
    0 ~ 4         5 ~ 9
0 ~ 2, 3 ~ 4, 5 ~ 7, 8 ~ 9
이런식으로 나뉘는 것. 
트리는 보통 어떻게 저장하는가. 
트리는 그래프이다. 그래프 중 어떤 특별한 성질을 갖는 것을 트리라고 한다. 
그래서 그래프랑 특별히 다르지 않다. 그런데 세그먼트 트리는 조금 다르다. 
세그먼트 트리는 루트가 있다. 루트가 없는 트리도 존재한다. 
루트가 있는 트리는 다른 형태를 갖는다. 항상 2개씩 나눠진다. 
맨 밑에 있는 노드와 그 위의 뎁스 차이는 1이 날 수밖에 없다. 그래서 2진트리 방식을 사용해주면 된다.
Binary Tree. 이걸 저장하는 방식은 많다. 그런데 Full Binary Tree가 있다. 꽉 차 있는 것. 
높이가 h인 FBT는 항상 2의 h제곱 -1개의 노드를 갖고 있다. 
다음으로는 complete binary tree. 이는 오른쪽의 노드 몇 개가 없는 것. 
이거를 저장하는 가장 효율적인 방법은 배열이다. 항상 2개씩 갖고 있다. 
heap도 이 방식을 사용한다. 세그먼트 트리도 complete binary tree랑 상당히 유사하다. 
그래서 배열을 이용해서 저장한다. 
항상 x번째의 인덱스는 왼쪽 자식이 2x, 오른쪽 자식이 2x+1. 
따라서 segment tree의 모든 노드는 3개의 값을 갖고 있다. 3개의 조합으로 만들어진다. 
(x, 2x, 2x+1)

모든 노드의 최소값을 구하기 전에 왼쪽 절반의 최소값을 구해주면 되고 오른쪽 절반의 최소값을 구해주면 된다. 

void init(vetor<int> &tree, vector<int> &a, int node, int start, int end) {
    if (start==end) {
        tree[node] == a[start];
    } else {
        init(tree, a, node*2, start, (start+end)/2);    => 왼쪽
        init(tree, a, node*2+1, (start+end)/2 +1, end); => 오른쪽
        tree[node] = min(tree[node*2], tree[node*2+1]); => 왼쪽과 오른쪽의 최소값을 저장한다.
    }
}
이 방법은 nlogn 시간이 걸린다.
다음에는 진짜로 최소값을 구해야한다. 

int query(vector<int> &tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) return -1;
    if (i <= start && end <= j) return tree[node];
    int m1 = query(tree, 2*node, start, (start+end)/2, i, j);
    int m2 = query(tree, 2*node+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) {
        return m2;
    } else if (m2==01) {
        return m1;
    } else {
        return min(m1, m2);
    }
}

이 코드는 logn이다. 제일 빠르고 좋은 알고리즘이다. 
세그먼트 트리는 nlogn + mlogn이다. (preprocessing + query)

만약 3을 변경한다고 하면 3이 포함되어 있는 모든 노드를 변경해주면 된다. 이것만 쭉 타고 들어가면서 변경해주면 된다. 
그래서 변경에서도 시간 복잡도가 제일 작기 때문에 세그먼트 트리가 제일 좋다. 

void update(vector<int> &tree, int node, int start, int end, int index, int value) {
    if (index < start || end < index) return;
    if (start==end) {
        tree[node] = value;
        return;
    }
    update(tree, node*2, start, (start+end)/2, index, value);
    update(tree, node*2+1, (start+end)/2+1, end, index, value);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

문제를 풀어보자. 유명한 문제. 영어로 약자가 있으면 유명한 문제. 
LIS. Longest Increasing Subsequence. 
가장 긴 증가하는 부분 수열 2
부분 수열은 항상 순서를 유지해야한다. 
증가한다는 것은 뒤로 가면서 증가해야한다는 것. 
가장 긴 것은 가장 많은 원소를 지녀야 한다는 것. 
수열 A = {10,20,10,30,20,50}에서는
10, 20, 30, 50이므로 4이다. 
이를 해결하는 방법으로는 3가지가 있다. 
첫 번째는 DP(Dynamic Programming)
    이 방법은 O(N^2)으로 해결할 수 있다. 
    A[i] 10 20   10  30   20 50
    D[i] 1  1+1  1   1+2  2  1+3

두 번째는 Greedy

세 번째는 Segment Tree
    핵심은 DP랑 유사. 앞에 있는 것 중에서 숫자가 작은 것, 그리고 가장 큰 값을 가진 것. 
    앞에 있는 것 중에 작은 수는 구간이 아니다. 가령 20보다 앞에 있으면서 작은 수는 첫 번째 수와 세 번째 수인데 이것은 구간이 아님. 그래서 구간을 만드는 것이 포인트. 
    구간인 형태로 어떻게 변형할 수 있을까. 
    구간의 형태를 저장하는 배열을 만들어줘야 한다. 
    작은 수라는 것이 구간이다. 가령 30부터 작은 수라고 하면 1부터 29까지의 구간인 것. 

    수열 = {1,3,2,4,3,4,2}
    tree[i] = 수 i를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이

    i    1  2  3  4  5  6  7
    A[i] 1  3  2  4  3  4  2
    
    i       1  2  3  4  5
    tree[i] 1  2  3  4  0
    
    N개의 수에 대해서 logn으로 탐색하니깐 총 nlogn의 시간 복잡도이다.

Fenwick Tree
합을 구할 때만 사용하는 특별한 트리. 세그먼트 트리보다 좋다.
왼쪽 자식 노드만 사용하여 트리를 만든다. 
i의 마지막 1의 값: i를 2진수로 나타냈을 때 가장 마지막 1이 나타내는 값. 
가령 12는 1100이고 제일 마지막 1은 4를 의미한다. 
11은 1011이고 제일 마지막 1은 1을 의미한다. 
 num = 1001101011101011000000000000
~num = 0110010100010100111111111111 (not연산 수행)
-num = 0110010100010101000000000000 (~num+1)
num & -num = 0000000000000001000000000000
마지막 1이 나온다. 

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i]
        i -= (i & -i);
    }
    return ans;
}
위의 코드는 합을 구하는 코드
int update(int i, int num) {
    while (i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}
위의 코드는 변경해주는 코드

구간의 형태가 나오고 구간의 합을 구해야 한다 할 때 펜윅 트리를 사용하면 된다. 

2차원으로도 할 수 있다. 
x에 대해서 그리고 y에 대해서 트리를 만들면 된다. 

어떤 배열이 있다. 이 배열에서 x번째부터 y번째까지 합을 구하는 코드를 작성해보자. 
for i in range(x, y+1):
    sum += A[i]
1차원 배열은 알겠는데 2차원 배열이 되는 순간 어렵다고 느껴지게 된다. 
(x1, y1) ~ (x2, y2)까지 합
for i in range(x1, x2+1):
    for j in range(y1, y2+1):
        sum += A[i][j]
마찬가지로 2차원 펜윅트리는 1차원 펜윅트리의 1차원 펜윅트리다. 
차원이 높아지면 for statement가 하나 는다고 생각하면 된다. 
int sum(int x, int y) {
    int ans = 0;
    for (int i=x; i>0; i-=i&-i) {
        for (int j=y; j>0; j-=j&-j) {
            ans += tree[i][j]
        }
    }
}

Network Flow

학생 5명이 있다. 역할도 5개가 있다. 
사람 a,b,c,d,e. 
역할 조장, 자료수집, 피피티, 발표, 무임 승차


"""
