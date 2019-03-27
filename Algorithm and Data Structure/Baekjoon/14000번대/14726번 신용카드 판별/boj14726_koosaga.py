for TEST in range(int(input())):
    card = list(map(int, input()))
    assert len(card) == 16
    for i in range(0, 16, 2):
        q = card[i]*2
        card[i] = q//10 + q%10
    print("T" if sum(card)%10 == 0 else "F")