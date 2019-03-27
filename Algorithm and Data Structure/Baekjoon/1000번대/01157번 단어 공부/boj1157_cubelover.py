s=input().upper()
a=[0]*26
for x in s:
  a[ord(x)-65]+=1
if a.count(max(a))>1:
  print("?")
else:
  print(chr(a.index(max(a))+65))