def wildcard_match(text, pattern, n, m):
    if m == 0:
        return n == 0
    elif n == 0:
        return pattern[-m] == '*' and wildcard_match(text, pattern, n, m-1)
    if text[-n] == pattern[-m] or pattern[-m] == '?':
        return wildcard_match(text, pattern, n - 1, m - 1)
    elif pattern[-m] == '*':
        return wildcard_match(text, pattern, n, m - 1) or wildcard_match(text, pattern, n-1, m)
    else:
        return False
