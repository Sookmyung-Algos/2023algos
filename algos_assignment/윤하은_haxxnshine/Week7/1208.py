import sys
input = sys.stdin.readline
from bisect import bisect_left, bisect_right

N,S = map(int,input().split())

seq = [*map(int,input().split())]

seq1 = seq[:N//2]
seq2 = seq[N//2:]

sum1 = []
sum2 = []

def SUM(seq,sumlist,x,start):
  for i in range(start+1,len(seq)):
    sumlist.append(x+seq[i])
    SUM(seq,sumlist,x+seq[i],i)

SUM(seq1,sum1,0,-1)
SUM(seq2,sum2,0,-1)

sum1.append(0)
sum2.append(0)
sum1.sort()
sum2.sort()

cnt = 0
for num in sum1:
  cnt += bisect_right(sum2,S-num)-bisect_left(sum2,S-num)

if S == 0:
  print(cnt-1)
else:
  print(cnt)
