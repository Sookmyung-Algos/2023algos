import sys

def getPi(P):
    pi = [0 for _ in range(0, len(P))]
    j = 0
    
    for i in range(1, len(P)):
        while j > 0 and P[i] != P[j]:
            j = pi[j - 1]

        if (P[i] == P[j]):
            j += 1
            pi[i] = j
    return pi[-1]

while True:
    S = sys.stdin.readline().rstrip('\n')
    if len(S) == 1 and S[0] == '.': exit(0)
    len_match = getPi(S)
    if len(S) % (len(S) - len_match) != 0:
        print(1)
    else:
        print(len(S) // (len(S) - len_match))

# 출처: https://velog.io/@jini_eun/%EB%B0%B1%EC%A4%80-4354%EB%B2%88-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%A0%9C%EA%B3%B1-Java-Python
