x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

n = (y2-y1)*(x3-x1) + (y1-y3)*(x2-x1)

if n == 0:
    print(0)
elif n < 0:
    print(1)
else:
    print(-1)
