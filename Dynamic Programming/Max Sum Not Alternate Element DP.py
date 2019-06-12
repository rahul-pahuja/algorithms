# Maximum Sum that can be made from a subset of arr(list)
# having elemnts which are not alternate to each other in arr.
def maxSum(arr):

    # length of arr
    n = len(arr)

    # list in which index i in list contains max sum that
    # can be made from first i elemnts of arr.
    max_sum_list = [0] * n

    # when i = 0, the max sum can be achieved to
    # arr[0], as arr list contain only one element.
    max_sum_list[0] = arr[0]

    # when i = 1, the max sum is equal to arr[1],
    # as the first element is alternate to the second one.
    max_sum_list[1] = arr[1]

    # when i = 2, the max sum is equal to sum
    # of first and third elemnt of arr.
    max_sum_list[2] = arr[0] + arr[2]

    for i in range(3, n):
        
        # Now, there are two cases for i elements in arr :
        # 1. when ith element contributes to the max sum then,
        max_sum_with_i = arr[i]
        
        # 1.a. sum of ith element of arr and max sum upto i-2 elements.
        # 1.b. sum of ith element of arr and max sum upto i-3 elements.
        max_sum_with_i += max(max_sum_list[i-2], max_sum_list[i-3])
        
        # 2. when ith elemnt doesn't contribute to the max sum then,
        max_sum_without_i = max_sum_list[i-1]

        max_sum_list[i] = max(max_sum_with_i, max_sum_without_i)

    # returning last element from max_sum_list,
    # as it gives max sum when all the elements
    # of arr are considered.
    return max_sum_list[n-1]
