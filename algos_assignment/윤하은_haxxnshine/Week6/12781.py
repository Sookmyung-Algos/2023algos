def ccw(x1, y1, x2, y2, x3, y3):
    n = (x1*y2 + x2*y3 + x3*y1)-(x2*y1 + x3*y2 + x1*y3)
    
    if n==0:
        return 0
    return abs(n)//n

a, b, c, d, e, f, g, h = map(int, input().split())

qwe = ccw(a, b, c, d, e, f)
qwr = ccw(a, b, c, d, g, h)
erq = ccw(e, f, g, h, a, b)
erw = ccw(e, f, g, h, c, d)

print(int(qwe*qwr < 0 and erq*erw < 0))
