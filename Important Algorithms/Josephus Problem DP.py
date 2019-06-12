def winner(n, k):
    arr = [0] * (n+1)
    arr[1] = 0
    for i in range(2, n+1):
        arr[i] = (arr[i-1] + k) % i
    return arr[-1]
