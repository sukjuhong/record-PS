n = int(input())
numlist = list(map(int,input().split()))
dp = [0 for _ in range(n)]

for p in range(n):
    dp[p] = numlist[p]

for i in range(n):
    for k in range(i,-1,-1):
        if numlist[k] < numlist[i] and dp[i] - numlist[i] < dp[k]:
            dp[i] = dp[k] + numlist[i]

print(max(dp)) 