n, p = map(int,input().split())
print("YES" if n/3 < p <= n-(n-1)/3 else "NO")