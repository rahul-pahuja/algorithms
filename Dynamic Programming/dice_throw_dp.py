def sum_ways(m, n, sum):
    lookup = [[0]*(sum + 1) for i in range(n + 1)]
    for i in range(1, min(m, sum) + 1):
        lookup[1][i] = 1
    for i in range(2, n + 1):
        for j in range(1, sum + 1):
            for k in range(1, min(m+1, j)):
                lookup[i][j] += lookup[i-1][j-k]
    return lookup[n][sum]
