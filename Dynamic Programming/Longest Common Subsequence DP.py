def lcs(str1, str2):
    m = len(str1)
    n = len(str2)
    index = 0
    lcs_str = ''
    lcs = [[0 for i in range(n+1)] for i in range(m+1)]
    for i in range(1, m+1):
        for j in range(1, n+1):
            if str1[i-1] == str2[j-1]:
                if index != i:
                    lcs_str += str1[i-1]
                    index += 1
                lcs[i][j] = 1 + lcs[i-1][j-1]
            else:
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])
    print(lcs_str)
    return lcs[m][n]
