def kmp(x):
    
    # length of list x
    n = len(x)

    # list of indices having frequency more than zero.
    indices = [i for i in range(n) if x[i]]

    # length of list of Non-zero elements.
    m = len(indices)

    result = ''
    
    if m == 1:
        result = chr(97 + indices[0]) * x[indices[0]]
    elif m > 1:
        min_index = 0
        for i in range(m):
            if x[indices[i]] < x[indices[min_index]]:
                min_index = i
        if min_index != 0:
            result = chr(97 + indices[min_index])
            for index in indices:
                if index == indices[min_index]:
                    result += chr(97 + index) * (x[index] - 1)
                else:
                    result += chr(97 + index) * x[index]
        else:
            if x[indices[min_index]] == 1:
                result += chr(97 + indices[min_index])
            elif x[indices[min_index]] == 2:
                result += chr(97 + indices[min_index]) * 2
            i = 0
            for i in range(x[indices[min_index]] - 2):
                result += chr(97 + indices[1]) + chr(97 + indices[min_index])
            result += chr(97 + indices[1]) * (x[indices[1]] - i)
            for i in range(2, m):
                result += chr(97 + indices[i]) * x[indices[i]]
    return result
