import sys
from itertools import combinations

n, l, r = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

def gcd(x, y):
   while y:
       x, y = y, x % y
   return x

def lcm(x, y):
   return x * y // gcd(x,y)

sums = 0
for i in range(n):
    sums += r//a[i] - l//a[i] + (not l%a[i])

for i in range(2, n+1):
    comb = list(combinations(a, i))
    temp = 0
    for c in comb:
        divider = lcm(c[0], c[1])
        for j in range(i-2):
            divider = lcm(divider, c[j+2])
        temp += r//divider - l//divider#(1~r 까지 배수) - (1~l까지 배수)
        temp += (not l%divider)
    if i%2:
        sums += temp#(전체 갯수에 더하기)
    else:
        sums -= temp
print(sums)
