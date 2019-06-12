def wildcard_match(text, pattern, m, n):

    if n == 0:
        return m == 0

    table = [[False for j in range(n+1)] for i in range(m+1)]
    table[0][0] = True
    
    for i in range(1, n+1):
        table[0][i] = table[0][i-1] and pattern[i-1] == '*'

    for row in range(1, m+1):
        for col in range(1, n+1):
            if text[row-1] == pattern[col-1] or pattern[col-1] == '?':
                table[row][col] = table[row-1][col-1]
            elif pattern[col-1] == '*':
                table[row][col] = table[row-1][col] or table[row][col-1]
            else:
                table[row][col] = False

    return table[m][n]
