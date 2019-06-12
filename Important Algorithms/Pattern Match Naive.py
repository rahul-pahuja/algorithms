# finding indices of substrings in a given string
# for example : string = 'AABAACAADAABAABA', substring = 'AABA'
# So, the resulted indices are : 0, 9, 12
def NaiveSearch(string, substring):
    m = len(string)
    n = len(substring)
    indices_list = []
    for index in range(m - n + 1):
        i = 0
        for i in range(n):
            if string[index + i] != substring[i]:
                break
        if i == n - 1:
            indices_list.append(index)
    print(indices_list)
