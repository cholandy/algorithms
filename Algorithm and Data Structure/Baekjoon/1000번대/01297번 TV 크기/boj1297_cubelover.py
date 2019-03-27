a,b,c=map(int,input().split())
print(int((a*a*b*b/(b*b+c*c))**.5),int((a*a*c*c/(b*b+c*c))**.5))