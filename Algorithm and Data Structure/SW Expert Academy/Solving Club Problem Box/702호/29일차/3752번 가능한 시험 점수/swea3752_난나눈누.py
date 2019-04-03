for tc in range(int(input())):
    n = int(input())
    scores = list(map(int, input().split()))
    prob = [0]
    check = [0]*(sum(scores)+1)
    for score in scores:
        for j in range(0, len(prob)):
            temp = score + prob[j]
            if not check[temp]:
                check[temp] = 1
                prob.append(temp)
    print(f"#{tc+1} {sum(check)+1}")