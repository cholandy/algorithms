def s(N, L, R, M):
  if M == 0: return 1
  ans = 0
  x = L&R&M
  while(x):
    lb = x&-x
    ans += s(N, ((L-lb)<<1)|1, ((R-lb)>>1)|(1<<(N-1)), M-lb)
    x -= lb
  return ans 

def s2(N, L, R, M):
  ans = 0
  for i in range((N+1)//2):
    lb = 1<<i
    v = s(N, ((L-lb)<<1)|1, ((R-lb)>>1)|(1<<(N-1)), M-lb)
    if((N&1) ==1 and i==(N-1)//2): ans += v 
    else: ans += 2*v
  return ans 

def np(N):
  return s2(N, 2**N-1, 2**N-1, 2**N-1)

print(np(int(input())))