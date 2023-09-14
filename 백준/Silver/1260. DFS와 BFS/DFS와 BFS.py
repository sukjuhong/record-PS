def dfs(start,visited):
    visited += [start]
    for search in range(len(graph[start])):
        if graph[start][search] and search not in visited:
            visited = dfs(search,visited)
    return visited 

def bfs(start):
    stack = [start]
    visited = [start]
    while stack:
        node = stack.pop(0)
        for search in range(len(graph[node])):
            if graph[node][search] and search not in visited:
                visited += [search]
                stack += [search]
    return visited

n,m,v = map(int,input().split())
graph = [[0]*(n+1) for _ in range(n+1)]
for i in range(m):
    link = list(map(int,input().split()))
    graph[link[0]][link[1]] = 1
    graph[link[1]][link[0]] = 1


print(*dfs(v,[]))
print(*bfs(v))