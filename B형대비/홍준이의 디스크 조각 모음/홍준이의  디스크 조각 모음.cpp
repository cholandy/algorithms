extern int getdiskSize();
extern int readDisk(int* buf, int addr, int size);
extern int move(int from, int to, int size);

struct Fragment{
        int ind, len;
};

int A[20003], N;
int B[20003];
int cnt[10], numStart[11];
Fragment nums[10][20003];
int numCnt[10];

int buf[64];
void usermove(int from, int to, int size)
{
        for (int i = 0; i < size; i++){
                buf[i] = A[from];
                A[from] = 0;
                from++;
        }

        for (int i = 0; i < size; i++)
                A[to++] = buf[i];
}

void getNums(int start, int num){
        numCnt[num] = 0;
        int k = 0;
        for(int i=start;i<N;i++){
                if(A[i] == num) k++;
                else if(k){
                        nums[num][numCnt[num]++] = {i-k, k};
                        k = 0;
                }
        }
        if(k)
                nums[num][numCnt[num]++] = {N-k, k};
}

void Set(int left, int right, int num){
        int count = 0;
        for(int i=left; i<=right; i++){
                if(i<right && A[i] != num) count++;
                else if(count){
                        int l = i - count;
                        int r = i;
                        while(l < r){
                                int k = numCnt[num] - 1;
                                int len = 64;
                                if(r-l < len) len = r - l;
                                if(nums[num][k].len < len) len = nums[num][k].len;

                                if(num == 0){
                                        usermove(l, nums[num][k].ind, len);
                                        move(l, nums[num][k].ind, len);
                                }
                                else {
                                        usermove(nums[num][k].ind, l, len);
                                        move(nums[num][k].ind, l, len);
                                }

                                nums[num][k].len -= len;
                                nums[num][k].ind += len;
                                l += len;
                                if(nums[num][k].len == 0) numCnt[num]--;
                        }
                        count = 0;
                }
        }
}

void defragment()
{
        N = getdiskSize();
        readDisk(A, 0, N);
        for(int i=0;i<10;i++) cnt[i] = 0;
        for(int i=0;i<N;i++) cnt[A[i]]++;
        for(int i=0;i<N;i++) B[i] = 0;
        for(int i=0,j=0;i<9;i++)
                for(int k=0;k<cnt[i+1];k++) B[j++] = i+1;

        for(int i=N-1;i>=0;i--) numStart[B[i]] = i;
        numStart[10] = numStart[0];

        for(int i=0;i<N;i++){
                if(A[i] == B[i]) continue;
                int j;
                for(j=i;j<N && A[j]!=B[j] && j-i+1<=cnt[0] && B[i]==B[j];j++);
                getNums(j, 0);
                Set(i, j, 0);

                getNums(numStart[B[i]+1], B[i]);
                Set(i, j, B[i]);
        }
}