# where n defines no. of sticks to buy,
# k defines no. of boxes for sale and
# b defines no. of boxes to buy on this trip

def bonetrousle(n, k, b):

    # list containing first b elements 

    list = [number for number in range(1, b+1)]

    # minimum sum that can be made using
    # b number of boxes i.e. first b elements

    min_sum = b * (b + 1) // 2

    # maximum sum that can be made using
    # b number of boxes i.e. last b elements

    max_sum = b * (2 * k - b + 1) // 2

    # if sum or n that needs to be made from k boxes
    # using b boxes is greater than max_sum or
    # lesser than min_sum then no such solution exists,
    # otherwise solution exists

    if n < min_sum or n > max_sum:
        return [-1]
    else:
        sum_list = min_sum
        no_to_add = k
        for index in range(1, b + 1):
            new_sum = sum_list - list[-index] + no_to_add
            if new_sum == n:
                list[-index] = no_to_add
                return list
            elif new_sum > n:
                list[-index] += n - sum_list
                return list
            list[-index] = no_to_add
            sum_list = new_sum
            no_to_add -= 1
