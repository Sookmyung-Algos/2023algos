import sys
input = sys.stdin.readline
t = int(input())

for _ in range(t) :

    n = int(input())
    phone = []
    isTrue = True

    for i in range(n) :
        phone.append(input().strip())

    phone.sort()

    for i in range(len(phone)-1) :
        if phone[i] == phone[i+1][:len(phone[i])] :
            isTrue = False
            break

    if isTrue :
        print("YES")
    else :
        print("NO")
