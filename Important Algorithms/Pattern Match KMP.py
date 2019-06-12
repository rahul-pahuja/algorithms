def KMPSearch(txt, pat):
    n = len(txt)
    m = len(pat)
    lps = get_lps(pat)
    i, j = 0, 0
    result = []
    while i < n:
        if txt[i] != pat[j]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
        else:
            i += 1
            j += 1
        if j == m:
            result.append(i-j)
            j = lps[-1]
    return result

def get_lps(s):
    n = len(s)
    lps = [0] * n
    for i in range(1, n):
        l = lps[i-1]
        while l > 0 and s[i] != s[l]:
            l = lps[l-1]
        if s[i] == s[l]:
            lps[i] = l + 1
        else:
            lps[i] = 0
    return lps
