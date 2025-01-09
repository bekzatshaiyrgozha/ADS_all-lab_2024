import sys

def find_negative_cycle(n, graph):
    INF = 10**9
    dist = [INF] * n
    parent = [-1] * n
    
    dist[0] = 0
    x = -1  
    
    for i in range(n):
        x = -1
        for u in range(n):
            for v in range(n):
                if graph[u][v] < INF: 
                    if dist[u] + graph[u][v] < dist[v]:
                        dist[v] = dist[u] + graph[u][v]
                        parent[v] = u
                        x = v
    
    if x == -1:
        print("NO")
        return
    
    for _ in range(n):
        x = parent[x]
    
    cycle = []
    current = x
    while True:
        cycle.append(current + 1)
        if current == x and len(cycle) > 1:
            break
        current = parent[current]
    
    cycle.reverse()
    print("YES")
    print(len(cycle))
    print(" ".join(map(str, cycle)))

if __name__ == "__main__":
    n = int(input())
    graph = []
    INF = 100000
    for _ in range(n):
        row = list(map(int, input().split()))
        graph.append([INF if x == INF else x for x in row])
    
    find_negative_cycle(n, graph)