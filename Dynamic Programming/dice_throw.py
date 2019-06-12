def sum_ways(m, n, sum):
    if n == 0:
        if sum == 0:
            return 1
        else:
            return 0
    total_combinations = 0
    for i in range(1, min(m, sum) + 1):
        total_combinations += sum_ways(m, n - 1, sum - i)
    return total_combinations
