while True :
    w, h = map(int, input().split())
    if w==0 and h==0 :
        break
    land = [input().split() for i in range(h)]
    v = [[False for c in range(w)] for r in range(h)]
    cnt = 0
    for r in range(h) :
        for c in range(w) :
            if land[r][c] == '0' or v[r][c] :
                continue
            st = [(r,c)]
            while len(st) :
                ri, ci = st.pop()
                if v[ri][ci] :
                    continue
                v[ri][ci] = True
                diff = ((ri+x,ci+y) for x in (-1,0,1) for y in (-1,0,1) if x or y)
                for dr, dc in diff :
                    if 0 <= dr < h and 0 <= dc < w and \
                       land[dr][dc] == '1' and not v[dr][dc] :
                        st.append((dr, dc))
            cnt += 1
    print(cnt)