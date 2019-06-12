def longest_increasing_subsequence_count(sequence):
    n = len(sequence)
    lis_count = [1] * n
    indices = [i for i in range(n)]
    for i in range(n):
        for j in range(i):
            if x[indices[j]] < x[i]:
                lis_count[i] = lis_count[j] + 1
                indices[i] = i
            else:
                if x[j] < x[i]:
                    lis_count[i] = 2
                    indices[i] = i
                elif lis_count[j] > lis_count[i]:
                    lis_count[i] = lis_count[j]
                    indices[i] = indices[j]
    print(indices)
    return lis_count
