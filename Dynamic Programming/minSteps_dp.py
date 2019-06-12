def minSteps(n):
    table = [0 for i in range(n+1)]
    for i in range(2, n+1):
        min_value = table[i-1]
        if i%2 == 0:
            min_value = min(min_value, table[i//2])
        if i%3 == 0:
            min_value = min(min_value, table[i//3])
        table[i] = 1 + min_value
    return table[n]
