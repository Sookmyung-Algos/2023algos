def MakeTable(P, KMPTable):
    j = 0
    for i in range(1, len(P)):
        while j > 0 and P[i] != P[j]: 
            j = KMPTable[j - 1]  
        if P[i] == P[j]:  
            j += 1 
            KMPTable[i] = j  


def KMP(T, P, KMPTable):
    MakeTable(P, KMPTable)
    j = 0
    P_size = len(P)
    for i in range(len(T)):
        while j > 0 and T[i] != P[j]:  
            j = KMPTable[j - 1] 
        if T[i] == P[j]:  
            if j == P_size - 1:
                return True
            else: 
                j += 1
    return False


n = int(input())
t = list(map(int, input().split()))
p = list(map(int, input().split()))

lt = [0 for _ in range(360000)]
lp = [0 for _ in range(360000)]

for i in t:
    lt[i] = 1
for i in p:
    lp[i] = 1

lt += lt
KMPTable = [0 for _ in range(len(lp))]

if KMP(lt, lp, KMPTable):
    print('possible')
else:
    print('impossible')
