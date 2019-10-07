p0, pa, pb = 1, 0, 0

for _ in range(int(input())):
    p0,pa,pb = (p0+pa+pb)%9901,(p0+pb)%9901,(p0+pa)%9901

print((p0+pa+pb)%9901)
