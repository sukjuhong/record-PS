n,m = map(int,input().split())
tree = list(map(int,input().split()))
left,right = 0,max(tree)

while left < right:
    mid = (left+right)//2
    s = 0
    bl,br = left,right
    for i in range(n):
        if tree[i] > mid:
            s += tree[i] - mid
    if s >= m:
        left = mid
    else:
        right = mid
    if bl == left and br == right:
        break
    
print(left)