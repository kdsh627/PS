import sys
from collections import deque
input = sys.stdin.readline
N, L = map(int,input().split())
num = list(map(int, input().split()))
temp = deque()
result = []
for i in range(N):
    index = i - L + 1 if i - L + 1 > 0 else 0
    if(not temp): temp.appendleft(i)
    else:
        while(temp):
            if (temp[0] < index): temp.popleft()
            elif (num[temp[(len(temp)-1)]] > num[i]): temp.pop()
            else: break
        temp.append(i)
    result.append(num[temp[0]] if num[temp[0]] < num[index] else num[index])
for i in range(N):
	print("{0} ".format(result[i]) ,end="")