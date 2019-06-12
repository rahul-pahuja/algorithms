def winner(n):
    if n < 3:
        return 1
    x = 2
    while x < n:
        x *= 2
    x //= 2
    result = n % x
    result = 2 * result + 1
    return result
